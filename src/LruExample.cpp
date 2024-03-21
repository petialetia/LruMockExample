#include <Fibonacci.hpp>

#include <boost/compute/detail/lru_cache.hpp>
#include <iostream>

int main()
{
    boost::compute::detail::lru_cache<size_t, size_t> cache_storage(20);

    std::cout << evalFibonacciCaching(5, cache_storage) << std::endl;
}
