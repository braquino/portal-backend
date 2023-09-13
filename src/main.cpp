#include "crow.h"
#include "crow/middlewares/cors.h"
#include "bkend-sql.hpp"

int main()
{
    crow::App<crow::CORSHandler> app;
    auto& cors = app.get_middleware<crow::CORSHandler>();
    cors
    .global()
        .origin("*")
        .headers("*")
        .methods("POST"_method, "GET"_method);

    CROW_LOG_INFO << "Checking connection variables";
    try
    {
        check_pq_con_envs();
    }
    catch (const std::exception &e)
    {
        CROW_LOG_ERROR << e.what();
        return 1;
    }

    CROW_ROUTE(app, "/")([]()
    { 
        return crow::response(200, "Hello world"); 
    });

    CROW_ROUTE(app, "/get_expenses").methods("POST"_method)([](const crow::request &req)
    {
        auto body = crow::json::load(req.body);
        if (!body)
            return crow::response(400, "{\"error\": \"bad request\"}");

        std::string date_from = "";
        if (body.has("date_from"))
            date_from = body["date_from"].s();

        std::string date_to = "";
        if (body.has("date_to"))
            date_to = body["date_to"].s();

        std::string query = expenses_query(date_from, date_to);
        auto [data, http_code] = fetch_query(query);
        
        return crow::response(http_code, data);
    });

    CROW_ROUTE(app, "/add_expense").methods("POST"_method)([](const crow::request &req)
    {
        auto body = crow::json::load(req.body);
        if (!body)
            return crow::response(400, "{\"error\": \"bad request\"}");

        if (body.has("date") && body.has("description") && body.has("value"))
        {
            std::string date = body["date"].s();
            std::string description = body["description"].s();
            std::string value = body["value"].s();

            std::string query = add_expense_query(date, description, value);
            CROW_LOG_INFO << query;
            auto [data, http_code] = exec_query(query);
        
            return crow::response(http_code, data);
        }
        else
        {
            return crow::response(400, 
                "{\"error\": \"The request must contain 'data', 'description' and 'value' on body\"}"
            );
        }
    });

    CROW_ROUTE(app, "/update_expense").methods("POST"_method)([](const crow::request &req)
    {
        auto body = crow::json::load(req.body);
        if (!body)
            return crow::response(400, "{\"error\": \"bad request\"}");

        if (body.has("date") && body.has("description") && body.has("value") && body.has("id"))
        {
            std::string id = body["id"].s();
            std::string date = body["date"].s();
            std::string description = body["description"].s();
            std::string value = body["value"].s();

            std::string query = update_expense_query(id, date, description, value);
            CROW_LOG_INFO << query;
            auto [data, http_code] = exec_query(query);
        
            return crow::response(http_code, data);
        }
        else
        {
            return crow::response(400, 
                "{\"error\": \"The request must contain 'id', 'data', 'description' and 'value' on body\"}"
            );
        }
    });

        CROW_ROUTE(app, "/delete_expense").methods("POST"_method)([](const crow::request &req)
    {
        auto body = crow::json::load(req.body);
        if (!body)
            return crow::response(400, "{\"error\": \"bad request\"}");

        if (body.has("id"))
        {
            std::string id = body["id"].s();

            std::string query = delete_expense_query(id);
            CROW_LOG_INFO << query;
            auto [data, http_code] = exec_query(query);
        
            return crow::response(http_code, data);
        }
        else
        {
            return crow::response(400, 
                "{\"error\": \"The request must contain 'id' on body\"}"
            );
        }
    });

    app.port(5000).multithreaded().run();
}