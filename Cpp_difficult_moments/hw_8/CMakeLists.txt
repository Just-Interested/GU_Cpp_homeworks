cmake_minimum_required(VERSION 3.0.0)
project(PhoneBookParser VERSION 0.1.0)

set(CMAKE_MESSAGE_CONTEXT_SHOW 1)

add_executable(g_test tests/test.cpp src/helper.cpp src/helper.h)
message(STATUS "gtest dir $ENV{GTEST_CYGWIN}/lib")

target_include_directories(
    g_test PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "$ENV{GTEST_CYGWIN}/include"
)


target_link_libraries(
    g_test PRIVATE
    "$ENV{GTEST_CYGWIN}/lib/libgtest.a"
    "$ENV{GTEST_CYGWIN}/lib/libgtest_main.a"
)

add_executable(main src/main.cpp src/helper.cpp src/helper.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
