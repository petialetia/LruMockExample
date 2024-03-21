#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <Fibonacci.hpp>

#include <boost/optional.hpp>
#include <boost/optional/optional_io.hpp>

template<typename Key, typename Value>
class MockLruCache
{
public:
    MOCK_METHOD(boost::optional<Value>, get, (const Key& key), ());
    MOCK_METHOD(void, insert, (const Key& key, const Value& value), ());
};

TEST(Fibonacci, MockCheckGetNothing)
{
    MockLruCache<std::size_t, std::size_t> lru_storage;

    EXPECT_CALL(lru_storage, get(0))
        .WillOnce(testing::Return(boost::none));

    EXPECT_CALL(lru_storage, insert(0, 0));

    auto answer = evalFibonacciCaching(0, lru_storage);
    EXPECT_EQ(answer, 0);
}

TEST(Fibonacci, MockCheckGetInserted)
{
    MockLruCache<std::size_t, std::size_t> lru_storage;

    EXPECT_CALL(lru_storage, get(0))
        .WillOnce(testing::Return(boost::none))
        .WillOnce(testing::Return(0));

    EXPECT_CALL(lru_storage, insert(0, 0));

    auto answer = evalFibonacciCaching(0, lru_storage);
    EXPECT_EQ(answer, 0);

    answer = evalFibonacciCaching(0, lru_storage);
    EXPECT_EQ(answer, 0);
}
