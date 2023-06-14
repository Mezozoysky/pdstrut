#include <pd/strut/char_type.hpp>
#include <cstdlib>


namespace pd::strut
{

constexpr char const * WHITESPACE{" \n\t\v\f\r"};
constexpr wchar_t const * W_WHITESPACE{L" \n\t\v\f\r"};
constexpr std::size_t WHITESPACE_CHARS_TOTAL{6u};


template<>
bool is_whitespace(char ch)
{
    for (std::size_t index = 0; index < WHITESPACE_CHARS_TOTAL; ++ index)
    {
        if (ch == WHITESPACE[index])
        {
            return true;
        }
    }
    return false;
}


template<>
bool is_whitespace(uchar ch)
{
    for (std::size_t index = 0; index < WHITESPACE_CHARS_TOTAL; ++ index)
    {
        if (ch == WHITESPACE[index])
        {
            return true;
        }
    }
    return false;
}


template<>
bool is_whitespace(wchar_t ch)
{
    for (std::size_t index = 0; index < WHITESPACE_CHARS_TOTAL; ++ index)
    {
        if (ch == W_WHITESPACE[index])
        {
            return true;
        }
    }
    return false;
}

} // namespace pd::strut
