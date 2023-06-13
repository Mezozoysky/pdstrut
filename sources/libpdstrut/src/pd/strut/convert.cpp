#include <pd/strut/convert.hpp>

#include <codecvt>
#include <locale>


namespace pd::strut
{

static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> FACET;


std::wstring utf_8_to_16(std::string const & narrow_str)
{
    return FACET.from_bytes(narrow_str);
}

std::string utf_16_to_8(std::wstring const & wide_str)
{
    return FACET.to_bytes(wide_str);
}


} // namespace pd::strut
