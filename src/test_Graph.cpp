#include <gtest/gtest.h>
#include "Graph.h"



/*TEST(TestGraph, Constructor)
{
    Graph g;
    
    ASSERT_TRUE(g != NULL);
    
    
}
*/

TEST(TestGraph, Add)
{
    Graph g;

    ASSERT_TRUE(g.add(1,2));
    ASSERT_TRUE(g.add(1,3));

    EXPECT_TRUE(g.hasEdge(1,2));
    EXPECT_TRUE(g.hasEdge(1,3));
}


TEST(TestGraph, Weight)
{
    Graph g;

    ASSERT_TRUE(g.add(1,2,10));
    ASSERT_TRUE(g.add(1,3,11));

    EXPECT_EQ(10, g.weight(1,2));
    EXPECT_EQ(11, g.weight(1,3));

}


TEST(TestGraph, RemoveEdge)
{
   Graph g;

    g.add(1,2,10);
    g.add(1,3,11);
    
    g.removeEdge(1,2);
    EXPECT_FALSE(g.hasEdge(1,2));
   
}


TEST(TestGraph, RemoveNode)
{
   Graph g;

    g.add(1,2);
    g.add(1,3);

    g.removeNode(1);
    EXPECT_FALSE(g.hasEdge(1,2));
   

}
