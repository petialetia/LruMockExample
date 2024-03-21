#pragma once

#include <cstddef>

std::size_t evalFibonacci(std::size_t index);

template<typename LruCache>
std::size_t evalFibonacciCaching(std::size_t index, LruCache& cache_storage)
{
    if (auto recalled_answer = cache_storage.get(index))
        return *recalled_answer;

    auto answer = evalFibonacci(index);

    cache_storage.insert(index, answer);

    return answer;
}
