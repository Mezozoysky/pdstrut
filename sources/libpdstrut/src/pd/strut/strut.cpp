#include <pd/strut/strut.hpp>


namespace pd::strut
{

constexpr char const * WHITESPACE{" \n\t\v\f\r"};
constexpr wchar_t const * W_WHITESPACE{L" \n\t\v\f\r"};
constexpr char16_t const * U16_WHITESPACE{u" \n\t\v\f\r"};
constexpr char32_t const * U32_WHITESPACE{U" \n\t\v\f\r"};
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

template<>
bool is_whitespace(char16_t ch)
{
    for (std::size_t index = 0; index < WHITESPACE_CHARS_TOTAL; ++ index)
    {
        if (ch == U16_WHITESPACE[index])
        {
            return true;
        }
    }
    return false;
}

template<>
bool is_whitespace(char32_t ch)
{
    for (std::size_t index = 0; index < WHITESPACE_CHARS_TOTAL; ++ index)
    {
        if (ch == U32_WHITESPACE[index])
        {
            return true;
        }
    }
    return false;
}

template<>
void ltrim_in(std::string & str)
{
    std::size_t first = str.find_first_not_of(WHITESPACE);
    if (first == std::string::npos)
    {
        str.clear();
        return;
    }
    str = str.substr(first);
}

template<>
void ltrim_in(std::wstring & str)
{
    std::size_t first = str.find_first_not_of(W_WHITESPACE);
    if (first == std::string::npos)
    {
        str.clear();
        return;
    }
    str = str.substr(first);
}

template<>
void ltrim_in(std::u16string & str)
{
    std::size_t first = str.find_first_not_of(U16_WHITESPACE);
    if (first == std::string::npos)
    {
        str.clear();
        return;
    }
    str = str.substr(first);
}

template<>
void ltrim_in(std::u32string & str)
{
    std::size_t first = str.find_first_not_of(U32_WHITESPACE);
    if (first == std::string::npos)
    {
        str.clear();
        return;
    }
    str = str.substr(first);
}

} // namespace pd::strut
