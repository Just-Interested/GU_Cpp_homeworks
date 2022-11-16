cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)


add_executable(main main.cpp)

target_include_directories(
    main PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/pcappp/header"
)

target_link_libraries(
    main PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/pcappp/libPcap++.a"
    "${CMAKE_CURRENT_SOURCE_DIR}/pcappp/libPacket++.a"
    "${CMAKE_CURRENT_SOURCE_DIR}/pcappp/libCommon++.a"
    pcap
    pthread
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
