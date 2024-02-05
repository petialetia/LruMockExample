#pragma once

#include <gtest/gtest.h>

#include <string>

template<typename FunctionT>
void checkOutput(FunctionT Functon, std::string expected)
{
    std::streambuf* output_buffer = std::cout.rdbuf();

    std::stringstream check_buffer;
    std::cout.rdbuf(check_buffer.rdbuf());

    Functon();

    EXPECT_EQ(check_buffer.str(), expected);

    std::cout.rdbuf(output_buffer);
}