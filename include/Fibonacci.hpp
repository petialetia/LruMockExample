#pragma once

#include <cstddef>
#include <variant>

constexpr std::size_t N_SLOTS_FOR_CACHE = 20;

template<typename LruCache>
std::size_t evalFibonacci(std::size_t index)
{
    static LruCache last_answers(N_SLOTS_FOR_CACHE);

    if (auto recalled_answer = last_answers.get(index))
        return *recalled_answer;

    auto answer = evalFibonacci<std::monostate>(index);

    last_answers.insert(index, answer);

    return answer;
}

template<>
inline std::size_t evalFibonacci<std::monostate>(std::size_t index)
{
    switch (index)
    {
        case 0: return 0;
        case 1: return 1;
        default: return evalFibonacci<std::monostate>(index - 1) + evalFibonacci<std::monostate>(index - 2);
    }
}
