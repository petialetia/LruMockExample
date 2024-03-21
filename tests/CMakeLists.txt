include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gmock_SOURCE_DIR}/include)

add_executable(FibonacciTests EXCLUDE_FROM_ALL MainTests.cpp FibonacciTests.cpp)
target_link_libraries(FibonacciTests PUBLIC GTest::gtest_main GTest::gmock Fibonacci)
