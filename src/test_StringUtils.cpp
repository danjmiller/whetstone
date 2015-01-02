#include <gtest/gtest.h>
#include <string>
#include <iostream>

#include "StringUtils.h"

using namespace std;

TEST(StringUtilsTests, ReverseString)
{
    string  simple = "TOG";
    StringUtils util;
    util.reverse(simple);
    ASSERT_STREQ("GOT",simple.c_str());

    string longer = "PANANAMA";
    util.reverse(longer);
    ASSERT_STREQ("AMANANAP", longer.c_str());

    string one = "A";
    util.reverse(one);
    ASSERT_STREQ("A",  one.c_str());

    string two = "AB";
    util.reverse(two);
    ASSERT_STREQ("BA",two.c_str());

}
