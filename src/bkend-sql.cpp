#include "bkend-sql.hpp"
#include "fmt/core.h"
#include "crow.h"
#include <sstream>
#include <regex>

PGconn *get_connection()
{
    PGconn *conn = PQconnectdb("");
    if (PQstatus(conn) == CONNECTION_OK)
    {
        CROW_LOG_INFO << "Connected do db";
        return conn;
    }
    CROW_LOG_ERROR << "Connection faild: " << PQerrorMessage(conn);
    PQfinish(conn);
    return NULL;
}

bool check_pq_con_envs()
{
    if (!std::getenv("PGHOST"))
        throw std::runtime_error("PGHOST env var not set");
    if (!std::getenv("PGPASSWORD"))
        throw std::runtime_error("PGPASSWORD env var not set");
    if (!std::getenv("PGPORT"))
        CROW_LOG_WARNING << "PGPORT env var not set, using default";
    if (!std::getenv("PGDATABASE"))
        CROW_LOG_WARNING << "PGDATABASE env var not set, using default";
    if (!std::getenv("PGUSER"))
        CROW_LOG_WARNING << "PGUSER env var not set, using default";

    return true;
}

std::string where_or_and(int count)
{
    return (count == 0) ? "WHERE" : "AND";
}

std::string expenses_query(const std::string &date_from, const std::string &date_to)
{
    int where_count = 0;
    std::string query = "SELECT id, date, description, value FROM expenses";
    if (!date_from.empty())
        query += fmt::format("\n{} date >= '{}'", where_or_and(where_count++), date_from);
    if (!date_to.empty())
        query += fmt::format("\n{} date <= '{}'", where_or_and(where_count++), date_to);
    return query + ";";
}

std::string as_json_field(const char* str)
{
    std::string fld(str);
    return std::regex_replace(fld, std::regex("\""), "\\\"");
}

std::string add_expense_query(const std::string& date, const std::string& description, const std::string& value)
{
    return fmt::format(
        "INSERT INTO expenses (date, description, value) VALUES ('{}', '{}', {});",
        date, description, value
    );
}

std::string update_expense_query(const std::string& id, const std::string& date, const std::string& description, const std::string& value)
{
    return fmt::format(
        "UPDATE expenses SET date = '{}', description = '{}', value = {} WHERE id = {};",
        date, description, value, id
    );
}

std::string delete_expense_query(const std::string& id)
{
    return fmt::format(
        "DELETE FROM expenses WHERE id = {};", id
    );
}

std::pair<std::string, int> exec_query(const std::string& query)
{
    PGconn* conn = get_connection();
    PGresult *res;

    if (!conn)
        return std::make_pair("{\"error\": \"db connection error\"}", 400);

    res = PQexec(conn, query.c_str());

    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        std::string err = as_json_field(PQerrorMessage(conn));
        PQclear(res);
        PQfinish(conn);
        CROW_LOG_ERROR << err;
        return std::make_pair(fmt::format("{{\"error\": \"{}\"}}", err), 400);
    }
    else
    {
        PQclear(res);
        PQfinish(conn);
        return std::make_pair("{\"status\": \"ok\"}", 200);
    }
}

std::pair<std::string, int> fetch_query(const std::string& query)
{
    PGconn* conn = get_connection();
    PGresult *res;

    if (!conn)
        return std::make_pair("{\"error\": \"db connection error\"}", 400);

    res = PQexec(conn, query.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        std::string err(PQerrorMessage(conn));
        CROW_LOG_ERROR << "SET failed: " << err;
        PQclear(res);
        PQfinish(conn);
        return std::make_pair(fmt::format("{{\"error\": \"{}\"}}", as_json_field(err.c_str())), 400);
    }
    else
    {
        try
        {
            int nFields = PQnfields(res);
            CROW_LOG_INFO << "Number of fields: " << nFields;
            std::vector<std::string> header{};
            for (int i = 0; i < nFields; i++)
                header.push_back(as_json_field(PQfname(res, i)));

            int nRows = PQntuples(res);
            CROW_LOG_INFO << "Number of rows: " << nRows;

            std::stringstream ss;
            ss << "[";
            for (int i=0; i < nRows; i++)
            {   
                if (i > 0)
                    ss << ",";
                ss << "{";
                for (int j=0; j < nFields; j++)
                {   
                    if (j > 0)
                        ss << ",";
                    ss << fmt::format("\"{}\":\"{}\"",
                                header[j],
                                as_json_field(PQgetvalue(res, i, j)));
                }
                ss << "}";
            }
            ss << "]";
            PQclear(res);
            PQfinish(conn);
            CROW_LOG_INFO << "read to return";
            return std::make_pair(ss.str(), 200);
        } catch (const std::exception& e) {
            CROW_LOG_ERROR << e.what();
            PQclear(res);
            PQfinish(conn);
            return std::make_pair(fmt::format("{{\"error\": \"{}\"}}", as_json_field(e.what())), 400);
        }
    }
    PQclear(res);
    PQfinish(conn);
    return std::make_pair("{\"error\": \"end of function error\"}", 400);
}
