#include <catch2/catch_test_macros.hpp>

#include <pd/strut/strut.hpp>
#include <pd/strut/char_type.hpp>

using namespace pd::strut;
using namespace std::literals;

#if defined(PDSTRUT_CHAR_CHAR)
TEST_CASE("is_whitespace char tests", "[strut][is_whitespace][char][basic]")
{
    char ch_new{'\n'};
    char ch_tab{'\t'};
    char ch_vtab{'\v'};
    char ch_feed{'\f'};
    char ch_cret{'\r'};
    char ch_space{' '};
    char ch_null{'\0'};
    char ch_alpha{'a'};
    char ch_digit{'8'};
    char ch_under{'_'};
    char ch_punkt{';'};

    REQUIRE(is_whitespace(ch_new));
    REQUIRE(is_whitespace(ch_tab));
    REQUIRE(is_whitespace(ch_vtab));
    REQUIRE(is_whitespace(ch_feed));
    REQUIRE(is_whitespace(ch_cret));
    REQUIRE(is_whitespace(ch_space));
    REQUIRE(!is_whitespace(ch_null));
    REQUIRE(!is_whitespace(ch_alpha));
    REQUIRE(!is_whitespace(ch_digit));
    REQUIRE(!is_whitespace(ch_under));
    REQUIRE(!is_whitespace(ch_punkt));
}

TEST_CASE("is_whitespace uchar tests", "[strut][is_whitespace][uchar][basic]")
{
    uchar ch_new{'\n'};
    uchar ch_tab{'\t'};
    uchar ch_vtab{'\v'};
    uchar ch_feed{'\f'};
    uchar ch_cret{'\r'};
    uchar ch_space{' '};
    uchar ch_null{'\0'};
    uchar ch_alpha{'a'};
    uchar ch_digit{'8'};
    uchar ch_under{'_'};
    uchar ch_punkt{';'};

    REQUIRE(is_whitespace(ch_new));
    REQUIRE(is_whitespace(ch_tab));
    REQUIRE(is_whitespace(ch_vtab));
    REQUIRE(is_whitespace(ch_feed));
    REQUIRE(is_whitespace(ch_cret));
    REQUIRE(is_whitespace(ch_space));
    REQUIRE(!is_whitespace(ch_null));
    REQUIRE(!is_whitespace(ch_alpha));
    REQUIRE(!is_whitespace(ch_digit));
    REQUIRE(!is_whitespace(ch_under));
    REQUIRE(!is_whitespace(ch_punkt));
}
#endif

#if defined(PDSTRUT_CHAR_WCHAR)
TEST_CASE("is_whitespace wchar_t tests", "[strut][is_whitespace][wchar_t][basic]")
{
    char ch_new{L'\n'};
    char ch_tab{L'\t'};
    char ch_vtab{L'\v'};
    char ch_feed{L'\f'};
    char ch_cret{L'\r'};
    char ch_space{L' '};
    char ch_null{L'\0'};
    char ch_alpha{L'a'};
    char ch_digit{L'8'};
    char ch_under{L'_'};
    char ch_punkt{L';'};

    REQUIRE(is_whitespace(ch_new));
    REQUIRE(is_whitespace(ch_tab));
    REQUIRE(is_whitespace(ch_vtab));
    REQUIRE(is_whitespace(ch_feed));
    REQUIRE(is_whitespace(ch_cret));
    REQUIRE(is_whitespace(ch_space));
    REQUIRE(!is_whitespace(ch_null));
    REQUIRE(!is_whitespace(ch_alpha));
    REQUIRE(!is_whitespace(ch_digit));
    REQUIRE(!is_whitespace(ch_under));
    REQUIRE(!is_whitespace(ch_punkt));
}
#endif

#if defined(PDSTRUT_CHAR_U16CHAR)
TEST_CASE("is_whitespace char16_t tests", "[strut][is_whitespace][char16_t][basic]")
{
    uchar ch_new{u'\n'};
    uchar ch_tab{u'\t'};
    uchar ch_vtab{u'\v'};
    uchar ch_feed{u'\f'};
    uchar ch_cret{u'\r'};
    uchar ch_space{u' '};
    uchar ch_null{u'\0'};
    uchar ch_alpha{u'a'};
    uchar ch_digit{u'8'};
    uchar ch_under{u'_'};
    uchar ch_punkt{u';'};

    REQUIRE(is_whitespace(ch_new));
    REQUIRE(is_whitespace(ch_tab));
    REQUIRE(is_whitespace(ch_vtab));
    REQUIRE(is_whitespace(ch_feed));
    REQUIRE(is_whitespace(ch_cret));
    REQUIRE(is_whitespace(ch_space));
    REQUIRE(!is_whitespace(ch_null));
    REQUIRE(!is_whitespace(ch_alpha));
    REQUIRE(!is_whitespace(ch_digit));
    REQUIRE(!is_whitespace(ch_under));
    REQUIRE(!is_whitespace(ch_punkt));
}
#endif

#if defined(PDSTRUT_CHAR_U32CHAR)
TEST_CASE("is_whitespace char32_t tests", "[strut][is_whitespace][char32_t][basic]")
{
    char ch_new{U'\n'};
    char ch_tab{U'\t'};
    char ch_vtab{U'\v'};
    char ch_feed{U'\f'};
    char ch_cret{U'\r'};
    char ch_space{U' '};
    char ch_null{U'\0'};
    char ch_alpha{U'a'};
    char ch_digit{U'8'};
    char ch_under{U'_'};
    char ch_punkt{U';'};

    REQUIRE(is_whitespace(ch_new));
    REQUIRE(is_whitespace(ch_tab));
    REQUIRE(is_whitespace(ch_vtab));
    REQUIRE(is_whitespace(ch_feed));
    REQUIRE(is_whitespace(ch_cret));
    REQUIRE(is_whitespace(ch_space));
    REQUIRE(!is_whitespace(ch_null));
    REQUIRE(!is_whitespace(ch_alpha));
    REQUIRE(!is_whitespace(ch_digit));
    REQUIRE(!is_whitespace(ch_under));
    REQUIRE(!is_whitespace(ch_punkt));
}
#endif


#if defined(PDSTRUT_CHAR_CHAR)
TEST_CASE("ltrim_in string tests", "[strut][ltrim_in][string][basic]")
{
    std::string str{"abc"s};
    ltrim_in(str);
    REQUIRE(str == "abc"s);

    str = " abc"s;
    ltrim_in(str);
    REQUIRE(str == "abc"s);

    str = " \n\t\v\f\rabc"s;
    ltrim_in(str);
    REQUIRE(str == "abc"s);

    str = "     \n\n      "s;
    ltrim_in(str);
    REQUIRE(str == ""s);

    str = ""s;
    ltrim_in(str);
    REQUIRE(str == ""s);
}
#endif

#if defined(PDSTRUT_CHAR_WCHAR)
TEST_CASE("ltrim_in wstring tests", "[strut][ltrim_in][wstring][basic]")
{
    std::wstring str{L"abc"s};
    ltrim_in(str);
    REQUIRE(str == L"abc"s);

    str = L" abc"s;
    ltrim_in(str);
    REQUIRE(str == L"abc"s);

    str = L" \n\t\v\f\rabc"s;
    ltrim_in(str);
    REQUIRE(str == L"abc"s);

    str = L"     \n\n      "s;
    ltrim_in(str);
    REQUIRE(str == L""s);

    str = L""s;
    ltrim_in(str);
    REQUIRE(str == L""s);
}
#endif

#if defined(PDSTRUT_CHAR_U16CHAR)
TEST_CASE("ltrim_in u16string tests", "[strut][ltrim_in][u16string][basic]")
{
    std::u16string str{u"abc"s};
    ltrim_in(str);
    REQUIRE(str == u"abc"s);

    str = u" abc"s;
    ltrim_in(str);
    REQUIRE(str == u"abc"s);

    str = u" \n\t\v\f\rabc"s;
    ltrim_in(str);
    REQUIRE(str == u"abc"s);

    str = u"     \n\n      "s;
    ltrim_in(str);
    REQUIRE(str == u""s);

    str = u""s;
    ltrim_in(str);
    REQUIRE(str == u""s);
}
#endif

#if defined(PDSTRUT_CHAR_U32CHAR)
TEST_CASE("ltrim_in u32string tests", "[strut][ltrim_in][u32string][basic]")
{
    std::u32string str{U"abc"s};
    ltrim_in(str);
    REQUIRE(str == U"abc"s);

    str = U" abc"s;
    ltrim_in(str);
    REQUIRE(str == U"abc"s);

    str = U" \n\t\v\f\rabc"s;
    ltrim_in(str);
    REQUIRE(str == U"abc"s);

    str = U"     \n\n      "s;
    ltrim_in(str);
    REQUIRE(str == U""s);

    str = U""s;
    ltrim_in(str);
    REQUIRE(str == U""s);
}
#endif

#if defined(PDSTRUT_CHAR_CHAR)
TEST_CASE("rtrim_in string tests", "[strut][rtrim_in][string][basic]")
{
    std::string str{"abc"s};
    rtrim_in(str);
    REQUIRE(str == "abc"s);

    str = "abc "s;
    rtrim_in(str);
    REQUIRE(str == "abc"s);

    str = "abc \n\t\v\f\r"s;
    rtrim_in(str);
    REQUIRE(str == "abc"s);

    str = "     \n\n      "s;
    rtrim_in(str);
    REQUIRE(str == ""s);

    str = ""s;
    rtrim_in(str);
    REQUIRE(str == ""s);
}
#endif

#if defined(PDSTRUT_CHAR_WCHAR)
TEST_CASE("rtrim_in wstring tests", "[strut][rtrim_in][wstring][basic]")
{
    std::wstring str{L"abc"s};
    rtrim_in(str);
    REQUIRE(str == L"abc"s);

    str = L"abc "s;
    rtrim_in(str);
    REQUIRE(str == L"abc"s);

    str = L"abc \n\t\v\f\r"s;
    rtrim_in(str);
    REQUIRE(str == L"abc"s);

    str = L"     \n\n      "s;
    rtrim_in(str);
    REQUIRE(str == L""s);

    str = L""s;
    rtrim_in(str);
    REQUIRE(str == L""s);
}
#endif

#if defined(PDSTRUT_CHAR_U16CHAR)
TEST_CASE("rtrim_in u16string tests", "[strut][rtrim_in][u16string][basic]")
{
    std::u16string str{u"abc"s};
    rtrim_in(str);
    REQUIRE(str == u"abc"s);

    str = u"abc "s;
    rtrim_in(str);
    REQUIRE(str == u"abc"s);

    str = u"abc \n\t\v\f\r"s;
    rtrim_in(str);
    REQUIRE(str == u"abc"s);

    str = u"     \n\n      "s;
    rtrim_in(str);
    REQUIRE(str == u""s);

    str = u""s;
    rtrim_in(str);
    REQUIRE(str == u""s);
}
#endif

#if defined(PDSTRUT_CHAR_U32CHAR)
TEST_CASE("rtrim_in u32string tests", "[strut][rtrim_in][u32string][basic]")
{
    std::u32string str{U"abc"s};
    rtrim_in(str);
    REQUIRE(str == U"abc"s);

    str = U"abc "s;
    rtrim_in(str);
    REQUIRE(str == U"abc"s);

    str = U"abc \n\t\v\f\r"s;
    rtrim_in(str);
    REQUIRE(str == U"abc"s);

    str = U"     \n\n      "s;
    rtrim_in(str);
    REQUIRE(str == U""s);

    str = U""s;
    rtrim_in(str);
    REQUIRE(str == U""s);
}
#endif

#if defined(PDSTRUT_CHAR_CHAR)
TEST_CASE("trim_in string tests", "[strut][trim_in][string][basic]")
{
    std::string str{"abc"s};
    trim_in(str);
    REQUIRE(str == "abc"s);

    str = " abc "s;
    trim_in(str);
    REQUIRE(str == "abc"s);

    str = "\r\f\v\t\n abc \n\t\v\f\r"s;
    trim_in(str);
    REQUIRE(str == "abc"s);

    str = "     \n\n      "s;
    trim_in(str);
    REQUIRE(str == ""s);

    str = ""s;
    trim_in(str);
    REQUIRE(str == ""s);
}
#endif

#if defined(PDSTRUT_CHAR_WCHAR)
TEST_CASE("trim_in wstring tests", "[strut][trim_in][wstring][basic]")
{
    std::wstring str{L"abc"s};
    trim_in(str);
    REQUIRE(str == L"abc"s);

    str = L" abc "s;
    trim_in(str);
    REQUIRE(str == L"abc"s);

    str = L"\r\f\v\t\n abc \n\t\v\f\r"s;
    trim_in(str);
    REQUIRE(str == L"abc"s);

    str = L"     \n\n      "s;
    trim_in(str);
    REQUIRE(str == L""s);

    str = L""s;
    trim_in(str);
    REQUIRE(str == L""s);
}
#endif

#if defined(PDSTRUT_CHAR_U16CHAR)
TEST_CASE("trim_in u16string tests", "[strut][trim_in][u16string][basic]")
{
    std::u16string str{u"abc"s};
    trim_in(str);
    REQUIRE(str == u"abc"s);

    str = u" abc "s;
    trim_in(str);
    REQUIRE(str == u"abc"s);

    str = u"\r\f\v\t\n abc \n\t\v\f\r"s;
    trim_in(str);
    REQUIRE(str == u"abc"s);

    str = u"     \n\n      "s;
    trim_in(str);
    REQUIRE(str == u""s);

    str = u""s;
    trim_in(str);
    REQUIRE(str == u""s);
}
#endif

#if defined(PDSTRUT_CHAR_U32CHAR)
TEST_CASE("trim_in u32string tests", "[strut][trim_in][u32string][basic]")
{
    std::u32string str{U"abc"s};
    trim_in(str);
    REQUIRE(str == U"abc"s);

    str = U" abc "s;
    trim_in(str);
    REQUIRE(str == U"abc"s);

    str = U"\r\f\v\t\n abc \n\t\v\f\r"s;
    trim_in(str);
    REQUIRE(str == U"abc"s);

    str = U"     \n\n      "s;
    trim_in(str);
    REQUIRE(str == U""s);

    str = U""s;
    trim_in(str);
    REQUIRE(str == U""s);
}
#endif


#if defined(PDSTRUT_CHAR_CHAR)
TEST_CASE("ltrim string tests", "[strut][ltrim][string][basic]")
{
    std::string_view str{"abc"sv};
    std::string_view str2{ltrim(str)};
    REQUIRE(str == "abc"sv);
    REQUIRE(str2 == "abc"sv);

    str = " abc"sv;
    str2 = ltrim(str);
    REQUIRE(str == " abc"sv);
    REQUIRE(str2 == "abc"sv);

    str = " \n\t\v\f\rabc"sv;
    str2 = ltrim(str);
    REQUIRE(str == " \n\t\v\f\rabc"sv);
    REQUIRE(str2 == "abc"sv);

    str = "     \n\n      "sv;
    str2 = ltrim(str);
    REQUIRE(str == "     \n\n      "sv);
    REQUIRE(str2 == ""sv);

    str = ""s;
    str2 = ltrim(str);
    REQUIRE(str == ""s);
    REQUIRE(str2 == ""s);
}
#endif

#if defined(PDSTRUT_CHAR_WCHAR)
TEST_CASE("ltrim wstring tests", "[strut][ltrim][wstring][basic]")
{
    std::wstring_view str{L"abc"sv};
    std::wstring_view str2{ltrim(str)};
    REQUIRE(str == L"abc"sv);
    REQUIRE(str2 == L"abc"sv);

    str = L" abc"sv;
    str2 = ltrim(str);
    REQUIRE(str == L" abc"sv);
    REQUIRE(str2 == L"abc"sv);

    str = L" \n\t\v\f\rabc"sv;
    str2 = ltrim(str);
    REQUIRE(str == L" \n\t\v\f\rabc"sv);
    REQUIRE(str2 == L"abc"sv);

    str = L"     \n\n      "sv;
    str2 = ltrim(str);
    REQUIRE(str == L"     \n\n      "sv);
    REQUIRE(str2 == L""sv);

    str = L""sv;
    str2 = ltrim(str);
    REQUIRE(str == L""sv);
    REQUIRE(str2 == L""sv);
}
#endif

#if defined(PDSTRUT_CHAR_U16CHAR)
TEST_CASE("ltrim u16string tests", "[strut][ltrim][u16string][basic]")
{
    std::u16string_view str{u"abc"sv};
    std::u16string_view str2{ltrim(str)};
    REQUIRE(str == u"abc"sv);
    REQUIRE(str2 == u"abc"sv);

    str = u" abc"sv;
    str2 = ltrim(str);
    REQUIRE(str == u" abc"sv);
    REQUIRE(str2 == u"abc"sv);

    str = u" \n\t\v\f\rabc"sv;
    str2 = ltrim(str);
    REQUIRE(str == u" \n\t\v\f\rabc"sv);
    REQUIRE(str2 == u"abc"sv);

    str = u"     \n\n      "sv;
    str2 = ltrim(str);
    REQUIRE(str == u"     \n\n      "sv);
    REQUIRE(str2 == u""sv);

    str = u""sv;
    str2 = ltrim(str);
    REQUIRE(str == u""sv);
    REQUIRE(str2 == u""sv);
}
#endif

#if defined(PDSTRUT_CHAR_U32CHAR)
TEST_CASE("ltrim u32string tests", "[strut][ltrim][u32string][basic]")
{
    std::u32string_view str{U"abc"sv};
    std::u32string_view str2{ltrim(str)};
    REQUIRE(str == U"abc"sv);
    REQUIRE(str2 == U"abc"sv);

    str = U" abc"sv;
    str2 = ltrim(str);
    REQUIRE(str == U" abc"sv);
    REQUIRE(str2 == U"abc"sv);

    str = U" \n\t\v\f\rabc"sv;
    str2 = ltrim(str);
    REQUIRE(str == U" \n\t\v\f\rabc"sv);
    REQUIRE(str2 == U"abc"sv);

    str = U"     \n\n      "sv;
    str2 = ltrim(str);
    REQUIRE(str == U"     \n\n      "sv);
    REQUIRE(str2 == U""sv);

    str = U""sv;
    str2 = ltrim(str);
    REQUIRE(str == U""sv);
    REQUIRE(str2 == U""sv);
}
#endif


#if defined(PDSTRUT_CHAR_CHAR)
TEST_CASE("rtrim string tests", "[strut][rtrim][string][basic]")
{
    std::string_view str{"abc"s};
    std::string_view str2{rtrim(str)};
    REQUIRE(str == "abc"s);
    REQUIRE(str2 == "abc"s);

    str = "abc "s;
    str2 = rtrim(str);
    REQUIRE(str == "abc "s);
    REQUIRE(str2 == "abc"s);

    str = "abc \n\t\v\f\r"s;
    str2 = rtrim(str);
    REQUIRE(str == "abc \n\t\v\f\r"s);
    REQUIRE(str2 == "abc"s);

    str = "     \n\n      "s;
    str2 = rtrim(str);
    REQUIRE(str == "     \n\n      "s);
    REQUIRE(str2 == ""s);

    str = ""s;
    str2 = rtrim(str);
    REQUIRE(str == ""s);
    REQUIRE(str2 == ""s);
}
#endif

#if defined(PDSTRUT_CHAR_WCHAR)
TEST_CASE("rtrim wstring tests", "[strut][rtrim][wstring][basic]")
{
    std::wstring_view str{L"abc"sv};
    std::wstring_view str2{rtrim(str)};
    REQUIRE(str == L"abc"sv);
    REQUIRE(str2 == L"abc"sv);

    str = L"abc "sv;
    str2 = rtrim(str);
    REQUIRE(str == L"abc "sv);
    REQUIRE(str2 == L"abc"sv);

    str = L"abc \n\t\v\f\r"sv;
    str2 = rtrim(str);
    REQUIRE(str == L"abc \n\t\v\f\r"sv);
    REQUIRE(str2 == L"abc"sv);

    str = L"     \n\n      "sv;
    str2 = rtrim(str);
    REQUIRE(str == L"     \n\n      "sv);
    REQUIRE(str2 == L""sv);

    str = L""sv;
    str2 = rtrim(str);
    REQUIRE(str == L""sv);
    REQUIRE(str2 == L""sv);
}
#endif

#if defined(PDSTRUT_CHAR_U16CHAR)
TEST_CASE("rtrim u16string tests", "[strut][rtrim][u16string][basic]")
{
    std::u16string_view str{u"abc"sv};
    std::u16string_view str2{rtrim(str)};
    REQUIRE(str == u"abc"sv);
    REQUIRE(str2 == u"abc"sv);

    str = u"abc "sv;
    str2 = rtrim(str);
    REQUIRE(str == u"abc "sv);
    REQUIRE(str2 == u"abc"sv);

    str = u"abc \n\t\v\f\r"sv;
    str2 = rtrim(str);
    REQUIRE(str == u"abc \n\t\v\f\r"sv);
    REQUIRE(str2 == u"abc"sv);

    str = u"     \n\n      "sv;
    str2 = rtrim(str);
    REQUIRE(str == u"     \n\n      "sv);
    REQUIRE(str2 == u""sv);

    str = u""s;
    str2 = rtrim(str);
    REQUIRE(str == u""sv);
    REQUIRE(str2 == u""sv);
}
#endif

#if defined(PDSTRUT_CHAR_U32CHAR)
TEST_CASE("rtrim u32string tests", "[strut][rtrim][u32string][basic]")
{
    std::u32string_view str{U"abc"sv};
    std::u32string_view str2{rtrim(str)};
    REQUIRE(str == U"abc"sv);
    REQUIRE(str2 == U"abc"sv);

    str = U"abc "sv;
    str2  = rtrim(str);
    REQUIRE(str == U"abc "sv);
    REQUIRE(str2 == U"abc"sv);

    str = U"abc \n\t\v\f\r"sv;
    str2 = rtrim(str);
    REQUIRE(str == U"abc \n\t\v\f\r"sv);
    REQUIRE(str2 == U"abc"sv);

    str = U"     \n\n      "sv;
    str2 = rtrim(str);
    REQUIRE(str == U"     \n\n      "sv);
    REQUIRE(str2 == U""sv);

    str = U""sv;
    str2 = rtrim(str);
    REQUIRE(str == U""sv);
    REQUIRE(str2 == U""sv);
}
#endif


#if defined(PDSTRUT_CHAR_CHAR)
TEST_CASE("trim string tests", "[strut][trim][string][basic]")
{
    std::string_view str{"abc"sv};
    std::string_view str2{trim(str)};
    REQUIRE(str == "abc"sv);
    REQUIRE(str2 == "abc"sv);

    str = " abc "sv;
    str2 = trim(str);
    REQUIRE(str == " abc "sv);
    REQUIRE(str2 == "abc"sv);

    str = "\r\f\v\t\n abc \n\t\v\f\r"sv;
    str2 = trim(str);
    REQUIRE(str == "\r\f\v\t\n abc \n\t\v\f\r"sv);
    REQUIRE(str2 == "abc"sv);

    str = "     \n\n      "sv;
    str2 = trim(str);
    REQUIRE(str == "     \n\n      "sv);
    REQUIRE(str2 == ""sv);

    str = ""sv;
    str2 = trim(str);
    REQUIRE(str == ""sv);
    REQUIRE(str2 == ""sv);
}
#endif

#if defined(PDSTRUT_CHAR_WCHAR)
TEST_CASE("trim wstring tests", "[strut][trim][wstring][basic]")
{
    std::wstring_view str{L"abc"sv};
    std::wstring_view str2{trim(str)};
    REQUIRE(str == L"abc"sv);
    REQUIRE(str2 == L"abc"sv);

    str = L" abc "sv;
    str2 = trim(str);
    REQUIRE(str == L" abc "sv);
    REQUIRE(str2 == L"abc"sv);

    str = L"\r\f\v\t\n abc \n\t\v\f\r"sv;
    str2 = trim(str);
    REQUIRE(str == L"\r\f\v\t\n abc \n\t\v\f\r"sv);
    REQUIRE(str2 == L"abc"sv);

    str = L"     \n\n      "sv;
    str2 = trim(str);
    REQUIRE(str == L"     \n\n      "sv);
    REQUIRE(str2 == L""sv);

    str = L""sv;
    str2 = trim(str);
    REQUIRE(str == L""sv);
    REQUIRE(str2 == L""sv);
}
#endif

#if defined(PDSTRUT_CHAR_U16CHAR)
TEST_CASE("trim u16string tests", "[strut][trim][u16string][basic]")
{
    std::u16string_view str{u"abc"sv};
    std::u16string_view str2{trim(str)};
    REQUIRE(str == u"abc"sv);
    REQUIRE(str2 == u"abc"sv);

    str = u" abc "sv;
    str2 = trim(str);
    REQUIRE(str == u" abc "sv);
    REQUIRE(str2 == u"abc"sv);

    str = u"\r\f\v\t\n abc \n\t\v\f\r"sv;
    str2 = trim(str);
    REQUIRE(str == u"\r\f\v\t\n abc \n\t\v\f\r"sv);
    REQUIRE(str2 == u"abc"sv);

    str = u"     \n\n      "sv;
    str2 = trim(str);
    REQUIRE(str == u"     \n\n      "sv);
    REQUIRE(str2 == u""sv);

    str = u""sv;
    str2 = trim(str);
    REQUIRE(str == u""sv);
    REQUIRE(str2 == u""sv);
}
#endif

#if defined(PDSTRUT_CHAR_U32CHAR)
TEST_CASE("trim u32string tests", "[strut][trim][u32string][basic]")
{
    std::u32string_view str{U"abc"sv};
    std::u32string_view str2{trim(str)};
    REQUIRE(str == U"abc"sv);
    REQUIRE(str2 == U"abc"sv);

    str = U" abc "sv;
    str2 = trim(str);
    REQUIRE(str == U" abc "sv);
    REQUIRE(str2 == U"abc"sv);

    str = U"\r\f\v\t\n abc \n\t\v\f\r"sv;
    str2 = trim(str);
    REQUIRE(str == U"\r\f\v\t\n abc \n\t\v\f\r"sv);
    REQUIRE(str2 == U"abc"sv);

    str = U"     \n\n      "sv;
    str2 = trim(str);
    REQUIRE(str == U"     \n\n      "sv);
    REQUIRE(str2 == U""sv);

    str = U""s;
    str2 = trim(str);
    REQUIRE(str == U""s);
    REQUIRE(str2 == U""s);
}
#endif
