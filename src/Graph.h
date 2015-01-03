#include <vector>

class Graph
{
public:
    Graph();
    Graph(bool directed);
    bool add(int a, int b, int weight=1);
    //bool removeEdge(int a, int b);
    //bool removeNode(int n);
    //void printGraph();

private:
    
    void resize(int dim);
    
    bool m_directed;
    std::vector< std::vector<int> > m_matrix;

};
