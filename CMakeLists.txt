cmake_minimum_required(VERSION 3.5)

PROJECT(portal-backend VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Crow CONFIG REQUIRED)
find_package(PostgreSQL REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(GTest)

include_directories(include external/include)

file(GLOB SRC_FILES 
  src/bkend-sql.cpp
)

add_executable(portal-backend src/main.cpp ${SRC_FILES})
target_link_libraries(portal-backend PRIVATE PostgreSQL::PostgreSQL Crow::Crow fmt::fmt)

file(GLOB TEST_FILES
  tests/test_backend.cpp
)

if(GTest_LIB)
  add_executable(test-backend ${TEST_FILES} ${SRC_FILES})
  target_link_libraries(test-backend PRIVATE PostgreSQL::PostgreSQL Crow::Crow fmt::fmt ${EXT_LIBS} GTest::gtest_main)
endif()
