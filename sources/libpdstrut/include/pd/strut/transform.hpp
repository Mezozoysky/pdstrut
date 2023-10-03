#pragma once

#include "char_type.hpp"
#include <string>
#include <string_view>
#include <algorithm>


namespace pd::strut
{

template<typename CharT>
void ltrim_in(std::basic_string<CharT> & str)
{
    str.erase(str.begin(), std::find_if_not(str.begin(), str.end(), is_whitespace<CharT>));
}


template<typename CharT>
void rtrim_in(std::basic_string<CharT> & str)
{
    str.erase(std::find_if_not(str.rbegin(), str.rend(), is_whitespace<CharT>).base(), str.end());
}


template<typename CharT>
void trim_in(std::basic_string<CharT> & str)
{
    ltrim_in(str);
    rtrim_in(str);
}


template<typename CharT>
std::basic_string<CharT> ltrim(CharT const * str,
                               std::size_t length = std::numeric_limits<std::size_t>::max())
{
    if (length == std::numeric_limits<std::size_t>::max())
    {
        length = std::char_traits<CharT>::length(str);
    }
    if (length == 0u)
    {
        return {};
    }
    std::size_t idx{0u};
    for (; idx < length; ++idx)
    {
        if (!is_whitespace<CharT>(str[idx]))
        {
            break;
        }
    }
    return {str + idx, length - idx};
}


template<typename CharT>
std::basic_string<CharT> ltrim(std::basic_string_view<CharT> str)
{
    return ltrim(str.data(), str.length());
}


template<typename CharT>
std::basic_string<CharT> ltrim(std::basic_string<CharT> str)
{
    return ltrim(str.data(), str.length());
}


template<typename CharT>
std::basic_string<CharT> rtrim(CharT const * str,
                               std::size_t length = std::numeric_limits<std::size_t>::max())
{
    if (length == std::numeric_limits<std::size_t>::max())
    {
        length = std::char_traits<CharT>::length(str);
    }
    if (length == 0u)
    {
        return {};
    }
    std::size_t idx{length - 1u};
    for (; idx >= 0u; --idx)
    {
        if (!is_whitespace<CharT>(str[idx]))
        {
            break;
        }
    }
    return {str, idx + 1u};
}


template<typename CharT>
std::basic_string<CharT> rtrim(std::basic_string_view<CharT> str)
{
    return rtrim(str.data(), str.length());
}


template<typename CharT>
std::basic_string<CharT> rtrim(std::basic_string<CharT> str)
{
    return rtrim(str.data(), str.length());
}


template<typename CharT>
std::basic_string<CharT> trim(CharT const * str,
                              std::size_t length = std::numeric_limits<std::size_t>::max())
{
    std::basic_string<CharT> tmp{ltrim(str, length)};
    tmp = rtrim(tmp.data(), tmp.length());
    return tmp;
}

template<typename CharT>
std::basic_string<CharT> trim(std::basic_string<CharT> str)
{
    return trim(str.data(), str.length());
}


template<typename CharT>
std::basic_string<CharT> trim(std::basic_string_view<CharT> str)
{
    return trim(str.data(), str.length());
}

} // namespace pd::strut
