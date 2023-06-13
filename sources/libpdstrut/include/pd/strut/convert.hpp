#pragma once

#include <string>


namespace pd::strut
{

std::wstring utf_8_to_16(std::string const & narrow_str);
std::string utf_16_to_8(std::wstring const & wide_str);

} // namespace pd::strut
