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

void Graph::clear()
{
    for(int i = 0; i < m_matrix.size(); i++)
    {
        for(int n = 0; n < m_matrix[i].size(); n++)
        {
            m_matrix[i][n] = 0;
        }
    }
}


bool Graph::add(int a, int b, int weight)
{
    int maxDim = max(a,b);
    if ( m_matrix.size() < maxDim )
    {
        resize(maxDim);
    }

    cout << "[ " << a << " , " << b << " ]: " << m_matrix[a][b] << endl;

    m_matrix[a][b] = weight;

    return true;
}


bool Graph::removeEdge(int a, int b)
{
    if( m_matrix.size() <= max(a,b) )
    {
        m_matrix[a][b] = 0;
        return true;
    }

    return false;
}

bool Graph::removeNode(int n)
{
    if( m_matrix.size() > n )
    {
        return false;
    }
    
    m_matrix[n].assign(m_matrix.size(), 0);

    for(std::vector<vector<int> >::iterator it = m_matrix.begin(); 
        it != m_matrix.end(); 
        ++it) 
    {
        //*it is a vector<int>
        (*it)[n] = 0;
    }
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

bool Graph::hasEdge(int a, int b) const
{
    return weight(a, b) > 0;
}

int Graph::weight(int a, int b) const
{
    return m_matrix[a][b];
}


bool Graph::isDirected() const
{
    return m_directed;
}
