#pragma once

#include <boost/compute/detail/lru_cache.hpp>

constexpr size_t N_SLOTS_FOR_CACHE = 20;

size_t evalFibonacci(size_t index);
