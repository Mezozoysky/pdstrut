#include <catch2/catch_test_macros.hpp>

#include <pd/strut/strut.hpp>

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

TEST_CASE("ltrim string tests", "[strut][ltrim][string][basic]")
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

TEST_CASE("ltrim wstring tests", "[strut][ltrim][wstring][basic]")
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

TEST_CASE("ltrim u16string tests", "[strut][ltrim][u16string][basic]")
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

TEST_CASE("ltrim u32string tests", "[strut][ltrim][u32string][basic]")
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
