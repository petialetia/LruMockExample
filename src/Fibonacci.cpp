#include <Fibonacci.hpp>

std::size_t evalFibonacci(std::size_t index)
{
    switch (index)
    {
        case 0: return 0;
        case 1: return 1;
        default: return evalFibonacci(index - 1) + evalFibonacci(index - 2);
    }
}
