#include <gtest/gtest.h>
#include "BitTools.h"
#include "limits.h"


TEST(TestBitTools, PrintInt)
{
    BitTools bt;

    std::string val = bt.printBinary((short)2);
    EXPECT_STREQ("0000000000000010",val.c_str());

    val = bt.printBinary((short)1);
    EXPECT_STREQ("0000000000000001",val.c_str());

    val = bt.printBinary((short)SHRT_MAX);
    EXPECT_STREQ("0111111111111111",val.c_str());

    val = bt.printBinary((ushort)USHRT_MAX);
    EXPECT_STREQ("1111111111111111",val.c_str());
}


TEST(TestBitTools, TestPretty)
{
   BitTools bt;

   std::string val = bt.printBinary((short)2, true);
   EXPECT_STREQ("00000000 00000010",val.c_str());

   val = bt.printBinary((int)2, true);
   EXPECT_STREQ("00000000 00000000 00000000 00000010",val.c_str());


}
