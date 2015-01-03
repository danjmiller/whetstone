#include <gtest/gtest.h>
#include "BinaryTree.h"


class BinaryTreeTest : public testing::Test{

protected:
    //member functions go here

    virtual void SetUp()
    {
         smallTree = new BinaryTree();
         smallTree->insert(1);
         smallTree->insert(2);
         smallTree->insert(3);

         deepTree = new BinaryTree();
         deepTree->insert(100);
         deepTree->insert(200);
         deepTree->insert(50);
         deepTree->insert(25);
         deepTree->insert(300);
         deepTree->insert(400);
         deepTree->insert(10);
         deepTree->insert(5);

        return;
    }

    virtual void TearDown()
    {

        return;
    }

    //Can use these members in your test cases
    //int m_foo;
    BinaryTree* smallTree;
    BinaryTree* deepTree;

};


TEST_F(BinaryTreeTest, Constructors)
{

    //Use a member from the fixture class
    //m_foo = 1;
    BinaryTree* tree = new BinaryTree();

    ASSERT_TRUE(tree != NULL);


    Node* n = new Node(1);
    ASSERT_EQ(1,n->value);

    BinaryTree* tree2 = new BinaryTree(n);
    ASSERT_TRUE(tree2 != NULL);

    delete tree;
    delete tree2;

}


TEST_F(BinaryTreeTest, Insert)
{

    ASSERT_EQ(3,smallTree->size);


     BinaryTree* mdeepTree = new BinaryTree();
         mdeepTree->insert(100);
         mdeepTree->insert(200);
         mdeepTree->insert(50);
         mdeepTree->insert(25);
         mdeepTree->insert(300);
         mdeepTree->insert(400);
         mdeepTree->insert(10);
         mdeepTree->insert(5);

    ASSERT_EQ(8,mdeepTree->size);


  
}
