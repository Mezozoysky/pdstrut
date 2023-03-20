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
    if (first == std::wstring::npos)
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
    if (first == std::u16string::npos)
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
    if (first == std::u32string::npos)
    {
        str.clear();
        return;
    }
    str = str.substr(first);
}


template<>
void rtrim_in(std::string & str)
{
    std::size_t last = str.find_last_not_of(WHITESPACE);
    if (last == std::string::npos)
    {
        str.clear();
        return;
    }
    str = str.substr(0u, last + 1u);
}

template<>
void rtrim_in(std::wstring & str)
{
    std::size_t last = str.find_last_not_of(W_WHITESPACE);
    if (last == std::wstring::npos)
    {
        str.clear();
        return;
    }
    str = str.substr(0u, last + 1u);
}

template<>
void rtrim_in(std::u16string & str)
{
    std::size_t last = str.find_last_not_of(U16_WHITESPACE);
    if (last == std::u16string::npos)
    {
        str.clear();
        return;
    }
    str = str.substr(0u, last + 1u);
}

template<>
void rtrim_in(std::u32string & str)
{
    std::size_t last = str.find_last_not_of(U32_WHITESPACE);
    if (last == std::string::npos)
    {
        str.clear();
        return;
    }
    str = str.substr(0u, last + 1u);
}


template<>
std::string_view ltrim(std::string_view str)
{
    std::string_view str2{};
    std::size_t first = str.find_first_not_of(WHITESPACE);
    if (first == std::string::npos)
    {
        return str2;
    }
    str2 = str;
    str2.remove_prefix(first);
    return str2;
}

template<>
std::wstring_view ltrim(std::wstring_view str)
{
    std::wstring_view str2{};
    std::size_t first = str.find_first_not_of(W_WHITESPACE);
    if (first == std::string::npos)
    {
        return str2;
    }
    str2 = str;
    str2.remove_prefix(first);
    return str2;
}

template<>
std::u16string_view ltrim(std::u16string_view str)
{
    std::u16string_view str2{};
    std::size_t first = str.find_first_not_of(U16_WHITESPACE);
    if (first == std::string::npos)
    {
        return str2;
    }
    str2 = str;
    str2.remove_prefix(first);
    return str2;
}

template<>
std::u32string_view ltrim(std::u32string_view str)
{
    std::u32string_view str2{};
    std::size_t first = str.find_first_not_of(U32_WHITESPACE);
    if (first == std::string::npos)
    {
        return str2;
    }
    str2 = str;
    str2.remove_prefix(first);
    return str2;
}


template<>
std::string_view rtrim(std::string_view str)
{
    std::string_view str2{};
    std::size_t last = str.find_last_not_of(WHITESPACE);
    if (last == std::string::npos)
    {
        return str2;
    }
    str2 = str;
    str2.remove_suffix(str.size() - last - 1u);
    return str2;
}

template<>
std::wstring_view rtrim(std::wstring_view str)
{
    std::wstring_view str2{};
    std::size_t last = str.find_last_not_of(W_WHITESPACE);
    if (last == std::wstring::npos)
    {
        return str2;
    }
    str2 = str;
    str2.remove_suffix(str.size() - last - 1u);
    return str2;
}

template<>
std::u16string_view rtrim(std::u16string_view str)
{
    std::u16string_view str2{};
    std::size_t last = str.find_last_not_of(U16_WHITESPACE);
    if (last == std::u16string::npos)
    {
        return str2;
    }
    str2 = str;
    str2.remove_suffix(str.size() - last - 1u);
    return str2;
}

template<>
std::u32string_view rtrim(std::u32string_view str)
{
    std::u32string_view str2{};
    std::size_t last = str.find_last_not_of(U32_WHITESPACE);
    if (last == std::u32string::npos)
    {
        return str2;
    }
    str2 = str;
    str2.remove_suffix(str.size() - last - 1u);
    return str2;
}

} // namespace pd::strut
