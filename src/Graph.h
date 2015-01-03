#include <vector>

class Graph
{
public:
    Graph();
    Graph(bool directed);
    bool add(int a, int b, int weight=1);
    bool removeEdge(int a, int b);
    bool removeNode(int n);
    bool isDirected() const;

    bool hasEdge(int a, int b) const;
    int weight(int a, int b) const;
    

private:
    
    void resize(int dim);    
    bool m_directed;

    std::vector< std::vector<int> > m_matrix;

};
