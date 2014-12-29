#include <gtest/gtest.h>
#include <vector>
#include "LinkedList.h"


using namespace std;

void printList(vector<Node*> v)
{
    std::cout << "[ ";

    for(std::vector<Node*>::iterator it = v.begin(); it != v.end(); ++it) {
        Node* n = *it;
        std::cout << n->value << " , "; 
    }

    std::cout << " ]" << std::endl;

}



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
    Node* c = new Node();
    c->value = 3;

    l->insertEnd(a);
    ASSERT_EQ(1, l->size());

    l->insertEnd(b);
    ASSERT_EQ(2, l->size());

    l->insertEnd(c);
    ASSERT_EQ(3, l->size());

    vector<Node*> dump = l->dumpList();
    ASSERT_FALSE(dump.empty());
    ASSERT_EQ(1,dump[0]->value);
    ASSERT_EQ(2,dump[1]->value);    
    ASSERT_EQ(3,dump[2]->value);    
  
    
}


TEST(LinkedList, InsertAfter)
{
    LinkedList* l = new LinkedList();
    
    Node* a = new Node();
    a->value = 1;
    Node* b = new Node();
    b->value = 2;
    Node* c = new Node();
    c->value = 3;
    Node* d = new Node();
    d->value = 4;

    l->insertEnd(a);
    l->insertEnd(b);
    l->insertEnd(c);
    l->insertEnd(d);
    
    vector<Node*> dump = l->dumpList();
    ASSERT_EQ(4,l->size());

    Node* newN = new Node();
    newN->value = 99;

    l->insertAfter(a,newN);
    //Should now have [1,99,2,3,4]
    ASSERT_EQ(5,l->size());
    dump = l->dumpList();
    ASSERT_EQ(99,dump[1]->value);

    Node* new2 = new Node();
    new2->value = 88;
    l->insertAfter(d,new2);
    
    //Should now have [1,99,2,3,4,88]
    ASSERT_EQ(6,l->size());
    dump = l->dumpList();
    ASSERT_EQ(88,dump[5]->value);
}

TEST(LinkedList, InsertBefore)
{
    LinkedList* l = new LinkedList();
    
    Node* a = new Node();
    a->value = 1;
    Node* b = new Node();
    b->value = 2;
    Node* c = new Node();
    c->value = 3;
    Node* d = new Node();
    d->value = 444;

    l->insertEnd(a);
    l->insertEnd(b);
    l->insertEnd(c);
    l->insertEnd(d);
    
    ASSERT_EQ(4,l->size());

    Node* newN = new Node();
    newN->value = 99;
    l->insertBefore(c,newN);

    //Should now have [1,2,99,3,4]  
    ASSERT_EQ(5,l->size());
    vector<Node*> dump = l->dumpList();
    ASSERT_EQ(2,dump[1]->value);
    ASSERT_EQ(99,dump[2]->value);
    ASSERT_EQ(3,dump[3]->value);


    Node* new2 = new Node();
    new2->value = 88;
    l->insertBefore(c,new2);
    
    //Should now have [1,2,99,88,3,4]
    ASSERT_EQ(6,l->size());
    dump = l->dumpList();
    ASSERT_EQ(88,dump[3]->value);
    ASSERT_EQ(99,dump[2]->value);
    ASSERT_EQ(3,dump[4]->value);

    //Do an insert near the end
    Node* new3 = new Node();
    new3->value = 77;
    l->insertBefore(d,new3);
    
    //Should now have [1,2,99,88,3,77,4]
    ASSERT_EQ(7,l->size());
    dump = l->dumpList();
    ASSERT_EQ(77,dump[5]->value);
}

TEST(LinkedList, Remove)
{
    LinkedList* l = new LinkedList();

    Node* a = new Node();
    a->value = 1;
    Node* b = new Node();
    b->value = 2;
    Node* c = new Node();
    c->value = 3;

    l->insertEnd(a);
    l->insertEnd(b);
    l->insertEnd(c);

    l->remove(b);
    vector<Node*> dump = l->dumpList();
    ASSERT_EQ(2,l->size());
    ASSERT_EQ(1,dump[0]->value);

    l->remove(a);
    ASSERT_EQ(1,l->size());
    dump = l->dumpList();
    ASSERT_EQ(3,dump[0]->value);
    ASSERT_EQ(NULL,dump[0]->next);
    ASSERT_EQ(NULL,dump[0]->prev);

    l->remove(c);
    ASSERT_EQ(0,l->size());
 

}
