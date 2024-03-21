#include <Fibonacci.hpp>

#include <boost/compute/detail/lru_cache.hpp>
#include <iostream>

int main()
{
    std::cout << evalFibonacci<boost::compute::detail::lru_cache>(5) << std::endl;
}
