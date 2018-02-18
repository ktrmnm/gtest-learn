cmake_minimum_required(VERSION 3.10)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(TestSample1 test_sample1.cpp)
target_link_libraries(TestSample1 Sample1 GTest::Main)
#include_directories(${PROJECT_SOURCE_DIR}/src ${GTEST_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/src)

# Google Testの各テストケースごとにCTestのテストを作成する
#gtest_add_tests(TARGET TestSample1)

# CTestのテストをひとつだけ作成する
add_test(NAME AllTests COMMAND TestSample1)
