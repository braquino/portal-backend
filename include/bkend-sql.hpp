#ifndef BKEND_SQL_HPP_
#define BKEND_SQL_HPP_

#include <memory>
#include <vector>
#include <utility>
#include <string>
#include <exception>
#include <chrono>
#include "libpq-fe.h"

struct Expense {
  int id;
  std::string date;
  std::string description;
  float value;
};

bool check_pq_con_envs();

std::string expenses_query(const std::string& date_from = "", const std::string& date_to = "");

std::string add_expense_query(const std::string& date, const std::string& description, const std::string& value);

std::string update_expense_query(const std::string& id, const std::string& date, const std::string& description, const std::string& value);

std::string delete_expense_query(const std::string& id);

std::pair<std::string, int> fetch_query(const std::string& query);

std::pair<std::string, int> exec_query(const std::string& query);

#endif // BKEND_SQL_HPP_