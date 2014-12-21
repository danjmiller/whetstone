#include <gtest/gtest.h>
#include "LinkedList.h"


TEST(LinkedList, Push)
{

    LinkedList* l = new LinkedList();
    
    ASSERT_TRUE(l != NULL);

    l->push_front(1);
    ASSERT_EQ(1, l->size());
    l->push_front(2);
    ASSERT_EQ(2, l->size());

}


TEST(LinkedList, Pop)
{

    LinkedList* l = new LinkedList();
    
    l->push_front(99);
    l->push_front(88);

    int val = l->front();
    ASSERT_EQ(88, val);
    l->pop();
    val = l->front();
    ASSERT_EQ(99, val); 
    ASSERT_EQ(1, l->size());

    l->pop();
    ASSERT_EQ(0, l->size());
}
