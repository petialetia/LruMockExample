find_package(GTest)

add_executable(HelloWorldTests EXCLUDE_FROM_ALL MainTests.cpp HelloWorldTests.cpp)
target_link_libraries(HelloWorldTests PUBLIC ${GTEST_LIBRARIES} HelloWorld)