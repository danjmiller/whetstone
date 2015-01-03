#include "Graph.h"
#include <iostream>     
#include <algorithm> 

using namespace std;

Graph::Graph(bool directed) : m_directed(directed)
{

}

Graph::Graph() : m_directed(false)
{

}


bool Graph::add(int a, int b, int weight)
{
    int maxDim = max(a,b);
    if ( m_matrix.size() < maxDim )
    {
        resize(maxDim);
    }

    m_matrix[a][b] = weight;

    return true;
}




void Graph::resize(int dim)
{
        m_matrix.resize(dim);
 
        for(std::vector<vector<int> >::iterator it = m_matrix.begin(); it != m_matrix.end(); ++it) 
        {
            it->resize(dim);
        }
    
}
