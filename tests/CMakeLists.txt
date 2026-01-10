include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(hello-cli-tests test_operations.cpp)

target_link_libraries(hello-cli-tests
    PRIVATE
        hello-cli-lib
        GTest::gtest_main
)

include(GoogleTest)

if(NOT CMAKE_CROSSCOMPILING)
    gtest_discover_tests(hello-cli-tests)
else()
    add_test(NAME hello-cli-tests COMMAND hello-cli-tests)
endif()
