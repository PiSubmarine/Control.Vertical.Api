cmake_minimum_required(VERSION 3.20)

include(FetchContent)

project(${PISUBMARINE_MODULE_NAME}.Test LANGUAGES CXX)

set(${PISUBMARINE_MODULE_NAME}.Test.Sources
        "PiSubmarine/Control/Vertical/Api/CommandTest.cpp"
        "PiSubmarine/Control/Vertical/Api/IControllerMockTest.cpp"
        "PiSubmarine/Control/Vertical/Api/IControllerTest.cpp")

enable_testing()

find_package(GTest)

add_executable(${PISUBMARINE_MODULE_NAME}.Test ${${PISUBMARINE_MODULE_NAME}.Test.Sources})
PiSubmarineInitTarget(${PISUBMARINE_MODULE_NAME}.Test)

target_link_libraries(${PISUBMARINE_MODULE_NAME}.Test PRIVATE ${PISUBMARINE_MODULE_NAME})
target_link_libraries(${PISUBMARINE_MODULE_NAME}.Test PRIVATE ${PISUBMARINE_MODULE_NAME}.Mock)
target_link_libraries(${PISUBMARINE_MODULE_NAME}.Test PRIVATE GTest::gtest_main)
include(GoogleTest)
if(CMAKE_CROSSCOMPILING)
    gtest_add_tests(TARGET ${PISUBMARINE_MODULE_NAME}.Test)
else()
    gtest_discover_tests(${PISUBMARINE_MODULE_NAME}.Test)
endif()
