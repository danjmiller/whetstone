#include <gtest/gtest.h>
#include <vector>
#include "LinkedList.h"


using namespace std;

TEST(LinkedList, BasicObject)
{
    LinkedList* l = new LinkedList();

    ASSERT_TRUE( l != NULL);
    ASSERT_EQ(0, l->size());
}

TEST(LinkedList, InsertBeginning)
{
    LinkedList* l = new LinkedList();

    Node* a = new Node();
    a->value = 1;
    Node* b = new Node();
    b->value = 2;

    l->insertBeginning(a);
    ASSERT_EQ(1, l->size());

    l->insertBeginning(b);
    ASSERT_EQ(2, l->size());
 
    
    vector<Node*> dump = l->dumpList();
    ASSERT_FALSE(dump.empty());
    EXPECT_EQ(2,dump[0]->value);
    EXPECT_EQ(1,dump[1]->value);    
    
   
}


TEST(LinkedList, InsertEnd)
{
    LinkedList* l = new LinkedList();

    Node* a = new Node();
    a->value = 1;
    Node* b = new Node();
    b->value = 2;

    l->insertEnd(a);
    ASSERT_EQ(1, l->size());

    l->insertEnd(b);
    ASSERT_EQ(2, l->size());

    vector<Node*> dump = l->dumpList();
    ASSERT_FALSE(dump.empty());
    ASSERT_EQ(1,dump[0]->value);
    ASSERT_EQ(2,dump[1]->value);    
  
    
}
