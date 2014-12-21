#include <gtest/gtest.h>
#include "LinkedList.h"


TEST(LinkedList, Push)
{

    LinkedList* l = new LinkedList();
    
    ASSERT_TRUE(l != NULL);

    l->push(1);
    ASSERT_EQ(1, l->size());
    l->push(2);
    ASSERT_EQ(2, l->size());

}


TEST(LinkedList, Pop)
{

    LinkedList* l = new LinkedList();
    
    l->push(99);
    l->push(88);

    int val = l->pop();
    ASSERT_EQ(1, l->size());
    ASSERT_EQ(88, val);
    val = l->pop();
    ASSERT_EQ(0, l->size());
    ASSERT_EQ(99, val);

}
