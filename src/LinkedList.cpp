#include <cstddef>
#include <stdio.h>

#include "LinkedList.h"

LinkedList::LinkedList() : m_size(0)
{
    m_head = NULL;
}

LinkedList::~LinkedList()
{


}

bool LinkedList::push(int value)
{
    
    Node* n = new Node();
    n->value = value;
    

    if(m_head == NULL)
    {
        m_head = n;
        m_head->next = NULL;
        m_head->prev = NULL;
        m_size++;
    }
    else
    {
        n->prev = m_head;
        m_head->next = n;
        m_head = n;
        m_size++;
    }

    return true;
}

int LinkedList::pop()
{
    int value = m_head->value;
    Node* new_head = m_head->prev;
    delete(m_head);
    m_head = new_head;
    m_size--;
    return value;
}

int LinkedList::size() const 
{
    return m_size;
}


