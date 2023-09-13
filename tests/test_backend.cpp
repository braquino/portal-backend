#include "gtest/gtest.h"
#include "bkend-sql.hpp"
#include <regex>


TEST(Bkend, expenseQuery)
{
  ASSERT_EQ(expenses_query(), 
    "SELECT id, date, description, value FROM expenses;");

  ASSERT_EQ(expenses_query("2023-01-01"), 
    "SELECT id, date, description, value FROM expenses\n"
    "WHERE date >= '2023-01-01';");

  ASSERT_EQ(expenses_query("2022-01-01", "2023-01-01"), 
    "SELECT id, date, description, value FROM expenses\n"
    "WHERE date >= '2022-01-01'\n"
    "AND date <= '2023-01-01';");

  ASSERT_EQ(expenses_query("", "2023-01-01"), 
    "SELECT id, date, description, value FROM expenses\n"
    "WHERE date <= '2023-01-01';");
}

TEST(Replace, asJsonString)
{
  auto as_json_field = [](const char* str)
  {
      std::string fld(str);
      return std::regex_replace(fld, std::regex("\""), "\\\"");
  };
  ASSERT_EQ("a tes\\\"t", as_json_field("a tes\"t"));
}