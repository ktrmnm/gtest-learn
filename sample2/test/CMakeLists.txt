cmake_minimum_required(VERSION 3.10)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(TestBell test_bell.cpp)
target_link_libraries(TestBell Bell GTest::Main)
include_directories(${PROJECT_SOURCE_DIR}/bell ${GTEST_INCLUDE_DIRS})
gtest_add_tests(TARGET TestBell)

add_executable(TestCommon test_common.cpp)
target_link_libraries(TestCommon GTest::Main)
# include_directories(${PROJECT_SOURCE_DIR}/bell)
gtest_add_tests(TARGET TestCommon)
