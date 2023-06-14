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
std::basic_string<CharT> ltrim(std::basic_string_view<CharT> const & str)
{
    auto it = std::find_if_not(str.begin(), str.end(), is_whitespace<CharT>);
    if (it == str.end())
    {
        return {};
    }
    return {it, str.end()};
}


template<typename CharT>
std::basic_string<CharT> rtrim(std::basic_string_view<CharT> str)
{
    auto it = std::find_if_not(str.rbegin(), str.rend(), is_whitespace<CharT>);
    if (it == str.rend())
    {
        return {};
    }
    return {str.begin(), it.base()};
}


template<typename CharT>
std::basic_string<CharT> trim(std::basic_string_view<CharT> str)
{
    return rtrim({ltrim(str)});
}

} // namespace pd::strut
