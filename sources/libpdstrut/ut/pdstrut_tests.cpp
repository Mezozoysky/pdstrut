#include <catch2/catch_test_macros.hpp>

#include <pd/strut/strut.hpp>
#include <fstream>


using namespace pd::strut;
using namespace std::literals;


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


TEST_CASE("ltrim string tests", "[strut][ltrim][string][basic]")
{
    std::string str{"abc"s};
    std::string str2{ltrim(str)};
    REQUIRE(str == "abc"s);
    REQUIRE(str2 == "abc"s);

    std::string_view strv{"abc"sv};
    str2 = ltrim(str);
    REQUIRE(strv.compare("abc"sv) == 0);
    REQUIRE(str2 == "abc"s);

    str2 = ltrim("abc");
    REQUIRE(str2 == "abc"s);

    str = " abc"s;
    str2 = ltrim(str);
    REQUIRE(str == " abc"s);
    REQUIRE(str2 == "abc"s);

    strv = " abc"sv;
    str2 = ltrim(strv);
    REQUIRE(strv.compare(" abc"sv) == 0);
    REQUIRE(str2 == "abc"s);

    str2 = ltrim(" abc");
    REQUIRE(str2 == "abc"s);

    str = " \n\t\v\f\rabc"s;
    str2 = ltrim(str);
    REQUIRE(str == " \n\t\v\f\rabc"s);
    REQUIRE(str2 == "abc"s);

    strv = " \n\t\v\f\rabc"sv;
    str2 = ltrim(strv);
    REQUIRE(strv.compare(" \n\t\v\f\rabc"sv) == 0);
    REQUIRE(str2 == "abc"s);

    str2 = ltrim(" \n\t\v\f\rabc");
    REQUIRE(str2 == "abc"s);

    str = "     \n\n      "s;
    str2 = ltrim(str);
    REQUIRE(str == "     \n\n      "s);
    REQUIRE(str2 == ""s);

    strv = "     \n\n      "sv;
    str2 = ltrim(strv);
    REQUIRE(strv.compare("     \n\n      "sv) == 0);
    REQUIRE(str2 == ""s);

    str2 = ltrim("     \n\n     ");
    REQUIRE(str2 == ""s);

    str = ""s;
    str2 = ltrim(str);
    REQUIRE(str == ""s);
    REQUIRE(str2 == ""s);

    strv = ""sv;
    str2 = ltrim(strv);
    REQUIRE(strv.compare(""sv) == 0);
    REQUIRE(str2 == ""s);

    str2 = ltrim("");
    REQUIRE(str2 == ""s);
}


TEST_CASE("ltrim wstring tests", "[strut][ltrim][wstring][basic]")
{
    std::wstring str{L"abc"s};
    std::wstring str2{ltrim(str)};
    REQUIRE(str == L"abc"s);
    REQUIRE(str2 == L"abc"s);

    std::wstring_view strv{L"abc"sv};
    str2 = ltrim(strv);
    REQUIRE(strv.compare(L"abc"sv) == 0);
    REQUIRE(str2 == L"abc"s);

    str2 = ltrim(L"abc");
    REQUIRE(str2 == L"abc"s);

    str = L" abc"s;
    str2 = ltrim(str);
    REQUIRE(str == L" abc"s);
    REQUIRE(str2 == L"abc"s);

    strv = L" abc"sv;
    str2 = ltrim(strv);
    REQUIRE(strv.compare(L" abc"sv) == 0);
    REQUIRE(str2 == L"abc"s);

    str2 = ltrim(L" abc");
    REQUIRE(str2 == L"abc"s);

    str = L" \n\t\v\f\rabc"s;
    str2 = ltrim(str);
    REQUIRE(str == L" \n\t\v\f\rabc"s);
    REQUIRE(str2 == L"abc"s);

    strv = L" \n\t\v\f\rabc"sv;
    str2 = ltrim(strv);
    REQUIRE(strv.compare(L" \n\t\v\f\rabc"sv) == 0);
    REQUIRE(str2 == L"abc"s);

    str2 = ltrim(L" \n\t\v\f\rabc");
    REQUIRE(str2 == L"abc"s);

    str = L"     \n\n      "s;
    str2 = ltrim(str);
    REQUIRE(str == L"     \n\n      "s);
    REQUIRE(str2 == L""s);

    strv = L"     \n\n      "sv;
    str2 = ltrim(strv);
    REQUIRE(strv.compare(L"     \n\n      "sv) == 0);
    REQUIRE(str2 == L""s);

    str2 = ltrim(L"     \n\n     ");
    REQUIRE(str2 == L""s);

    str = L""s;
    str2 = ltrim(str);
    REQUIRE(str == L""s);
    REQUIRE(str2 == L""s);

    strv = L""sv;
    str2 = ltrim(strv);
    REQUIRE(strv.compare(L""sv) == 0);
    REQUIRE(str2 == L""s);

    str2 = ltrim(L"");
    REQUIRE(str2 == L""s);
}


TEST_CASE("rtrim string tests", "[strut][rtrim][string][basic]")
{
    std::string str{"abc"s};
    std::string str2{rtrim(str)};
    REQUIRE(str == "abc"s);
    REQUIRE(str2 == "abc"s);

    std::string_view strv{"abc"sv};
    str2 = rtrim(strv);
    REQUIRE(strv.compare("abc"sv) == 0);
    REQUIRE(str2 == "abc"s);

    str2 = rtrim("abc");
    REQUIRE(str2 == "abc"s);

    str = "abc "s;
    str2 = rtrim(str);
    REQUIRE(str == "abc "s);
    REQUIRE(str2 == "abc"s);

    strv = "abc "sv;
    str2 = rtrim(strv);
    REQUIRE(strv.compare("abc "sv) == 0);
    REQUIRE(str2 == "abc"s);

    str2 = rtrim("abc ");
    REQUIRE(str2 == "abc"s);

    str = "abc \n\t\v\f\r"s;
    str2 = rtrim(str);
    REQUIRE(str == "abc \n\t\v\f\r"s);
    REQUIRE(str2 == "abc"s);

    strv = "abc \n\t\v\f\r"sv;
    str2 = rtrim(strv);
    REQUIRE(strv.compare("abc \n\t\v\f\r"sv) == 0);
    REQUIRE(str2 == "abc"s);

    str2 = rtrim("abc \n\t\v\f\r");
    REQUIRE(str2 == "abc"s);

    str = "     \n\n      "s;
    str2 = rtrim(str);
    REQUIRE(str == "     \n\n      "s);
    REQUIRE(str2 == ""s);

    strv = "     \n\n      "sv;
    str2 = rtrim(strv);
    REQUIRE(strv.compare("     \n\n      "sv) == 0);
    REQUIRE(str2 == ""s);

    str2 = rtrim("     \n\n     ");
    REQUIRE(str2 == ""s);

    str = ""s;
    str2 = rtrim(str);
    REQUIRE(str == ""s);
    REQUIRE(str2 == ""s);

    strv = ""sv;
    str2 = rtrim(strv);
    REQUIRE(strv.compare(""sv) == 0);
    REQUIRE(str2 == ""s);

    str2 = rtrim("");
    REQUIRE(str2 == ""s);
}


TEST_CASE("rtrim wstring tests", "[strut][rtrim][wstring][basic]")
{
    std::wstring str{L"abc"s};
    std::wstring str2{rtrim(str)};
    REQUIRE(str == L"abc"s);
    REQUIRE(str2 == L"abc"s);

    std::wstring_view strv{L"abc"sv};
    str2 = rtrim(strv);
    REQUIRE(strv.compare(L"abc"sv) == 0);
    REQUIRE(str2 == L"abc"s);

    str2 = rtrim(L"abc");
    REQUIRE(str2 == L"abc"s);

    str = L"abc "s;
    str2 = rtrim(str);
    REQUIRE(str == L"abc "s);
    REQUIRE(str2 == L"abc"s);

    strv = L"abc "sv;
    str2 = rtrim(strv);
    REQUIRE(strv.compare(L"abc "sv) == 0);
    REQUIRE(str2 == L"abc"s);

    str2 = rtrim(L"abc ");
    REQUIRE(str2 == L"abc"s);

    str = L"abc \n\t\v\f\r"s;
    str2 = rtrim(str);
    REQUIRE(str == L"abc \n\t\v\f\r"s);
    REQUIRE(str2 == L"abc"s);

    strv = L"abc \n\t\v\f\r"sv;
    str2 = rtrim(strv);
    REQUIRE(strv.compare(L"abc \n\t\v\f\r"sv) == 0);
    REQUIRE(str2 == L"abc"s);

    str2 = rtrim(L"abc \n\t\v\f\r");
    REQUIRE(str2 == L"abc"s);

    str = L"     \n\n      "s;
    str2 = rtrim(str);
    REQUIRE(str == L"     \n\n      "s);
    REQUIRE(str2 == L""s);

    strv = L"     \n\n      "sv;
    str2 = rtrim(strv);
    REQUIRE(strv.compare(L"     \n\n      "sv) == 0);
    REQUIRE(str2 == L""s);

    str2 = rtrim(L"     \n\n     ");
    REQUIRE(str2 == L""s);

    str = L""s;
    str2 = rtrim(str);
    REQUIRE(str == L""s);
    REQUIRE(str2 == L""s);

    strv = L""sv;
    str2 = rtrim(strv);
    REQUIRE(strv.compare(L""sv) == 0);
    REQUIRE(str2 == L""s);

    str2 = rtrim(L"");
    REQUIRE(str2 == L""s);
}


TEST_CASE("trim string tests", "[strut][trim][string][basic]")
{
    std::string str{"abc"s};
    std::string str2{trim(str)};
    REQUIRE(str == "abc"s);
    REQUIRE(str2 == "abc"s);

    std::string_view strv{"abc"sv};
    str2 = trim(strv);
    REQUIRE(strv.compare("abc"sv) == 0);
    REQUIRE(str2 == "abc"s);

    str2 = trim("abc");
    REQUIRE(str2 == "abc"s);

    str = " abc "s;
    str2 = trim(str);
    REQUIRE(str == " abc "s);
    REQUIRE(str2 == "abc"s);

    strv = " abc "sv;
    str2 = trim(strv);
    REQUIRE(strv.compare(" abc "sv) == 0);
    REQUIRE(str2 == "abc"s);

    str2 = trim(" abc ");
    REQUIRE(str2 == "abc");

    str = "\r\f\v\t\n abc \n\t\v\f\r"s;
    str2 = trim(str);
    REQUIRE(str == "\r\f\v\t\n abc \n\t\v\f\r"s);
    REQUIRE(str2 == "abc"s);

    strv = "\r\f\v\t\n abc \n\t\v\f\r"sv;
    str2 = trim(strv);
    REQUIRE(strv.compare("\r\f\v\t\n abc \n\t\v\f\r"sv) == 0);
    REQUIRE(str2 == "abc"s);

    str2 = trim("\r\f\v\t\n abc \n\t\v\f\r");
    REQUIRE(str2 == "abc"s);

    str = "     \n\n      "s;
    str2 = trim(str);
    REQUIRE(str == "     \n\n      "s);
    REQUIRE(str2 == ""s);

    strv = "     \n\n      "sv;
    str2 = trim(strv);
    REQUIRE(strv.compare("     \n\n      "sv) == 0);
    REQUIRE(str2 == ""s);

    str2 = trim("     \n\n      ");
    REQUIRE(str2 == ""s);

    str = ""s;
    str2 = trim(str);
    REQUIRE(str == ""s);
    REQUIRE(str2 == ""s);

    strv = ""sv;
    str2 = trim(strv);
    REQUIRE(strv.compare(""sv) == 0);
    REQUIRE(str2 == ""s);

    str2 = trim("");
    REQUIRE(str2 == ""s);
}


TEST_CASE("trim wstring tests", "[strut][trim][wstring][basic]")
{
    std::wstring str{L"abc"s};
    std::wstring str2{trim(str)};
    REQUIRE(str == L"abc"s);
    REQUIRE(str2 == L"abc"s);

    std::wstring_view strv{L"abc"sv};
    str2 = trim(strv);
    REQUIRE(strv.compare(L"abc"sv) == 0);
    REQUIRE(str2 == L"abc"s);

    str2 = trim(L"abc");
    REQUIRE(str2 == L"abc");

    str = L" abc "s;
    str2 = trim(str);
    REQUIRE(str == L" abc "s);
    REQUIRE(str2 == L"abc"s);

    strv = L" abc "sv;
    str2 = trim(strv);
    REQUIRE(strv.compare(L" abc "sv) == 0);
    REQUIRE(str2 == L"abc"s);

    str2 = trim(L" abc ");
    REQUIRE(str2 == L"abc"s);

    str = L"\r\f\v\t\n abc \n\t\v\f\r"s;
    str2 = trim(str);
    REQUIRE(str == L"\r\f\v\t\n abc \n\t\v\f\r"s);
    REQUIRE(str2 == L"abc"s);

    strv = L"\r\f\v\t\n abc \n\t\v\f\r"sv;
    str2 = trim(strv);
    REQUIRE(strv.compare(L"\r\f\v\t\n abc \n\t\v\f\r"sv) == 0);
    REQUIRE(str2 == L"abc"s);

    str2 = trim(L"\r\f\v\t\n abc \n\t\v\f\r");
    REQUIRE(str2 == L"abc"s);

    str = L"     \n\n      "s;
    str2 = trim(str);
    REQUIRE(str == L"     \n\n      "s);
    REQUIRE(str2 == L""s);

    strv = L"     \n\n      "sv;
    str2 = trim(strv);
    REQUIRE(strv.compare(L"     \n\n      "sv) == 0);
    REQUIRE(str2 == L""s);

    str2 = trim(L"     \n\n      ");
    REQUIRE(str2 == L""s);

    str = L""s;
    str2 = trim(str);
    REQUIRE(str == L""s);
    REQUIRE(str2 == L""s);

    strv = L""sv;
    str2 = trim(strv);
    REQUIRE(strv.compare(L""sv) == 0);
    REQUIRE(str2 == L""s);

    str2 = trim(L"");
    REQUIRE(str2 == L""s);
}


TEST_CASE("utf-8 to utf-16 conversion correctness", "[strut][utf_8_to_16][string][wstring][basic]")
{
    REQUIRE(std::is_same_v<std::string::value_type, char>);
    REQUIRE(std::is_same_v<std::wstring::value_type, wchar_t>);

    std::string narrow{"Засада"s};
    REQUIRE(narrow.length() == 12u);
    REQUIRE((uchar)(narrow[0]) == 0xd0);
    REQUIRE((uchar)(narrow[1]) == 0x97);

    std::wstring wide{utf_8_to_16(narrow)};
    REQUIRE(narrow == "Засада"s);
    // REQUIRE(wide == L"Засада"s);
    REQUIRE(wide.length() == 6u);
    REQUIRE(wide[0] == 0x0417);
}

#include <iostream>

TEST_CASE("utf-16 to utf-8 conversion correctness", "[strut][utf_16_to_8][string][wstring][basic]")
{
    std::wstring wide{L"Բարեւ"s};
    REQUIRE(wide.length() == 10u);
    REQUIRE((unsigned)wide[0] == 0x0532);
    std::wcout << L"wide: "s << wide << L"\n";

    std::string narrow{utf_16_to_8(wide)};
    REQUIRE(wide == L"Բարեւ"s);
    REQUIRE(narrow == "Բարեւ"s);
    REQUIRE(narrow.length() == 10u);
    REQUIRE((uchar)(narrow[0]) == 0xd4);
    REQUIRE((uchar)(narrow[1]) == 0xb2);
}
