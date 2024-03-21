#include <Fibonacci.hpp>

size_t evalFibonacci(size_t index)
{
    static boost::compute::detail::lru_cache<size_t, size_t> last_answers(N_SLOTS_FOR_CACHE);

    if (auto recalled_answer = last_answers.get(index))
        return *recalled_answer;

    auto answer = [&]() -> size_t {
        switch (index)
        {
            case 0: return 0;
            case 1: return 1;
            default: return evalFibonacci(index - 1) + evalFibonacci(index - 2);
        }
    }();

    last_answers.insert(index, answer);

    return answer;
}
