#pragma once

#include <string>
// #include <string_view>
#include <vector>
// #include <type_traits>
// #include <limits>


namespace pd::strut
{

using uchar = unsigned char;
using str_list = std::vector<std::string>;
using sv_list = std::vector<std::string_view>;


template<typename CharT>
bool is_whitespace(CharT ch);


template<typename CharT>
void ltrim_in(std::basic_string<CharT> & str);
// template<typename CharT>
// void rtrim_in(std::basic_string<CharT> & str);
// template<typename CharT>
// void trim_in(std::basic_string<CharT> & str);

} // namespace pd::strut
