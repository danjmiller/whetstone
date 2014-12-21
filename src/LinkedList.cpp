#include <cstddef>
#include <stdio.h>
#include <iostream>

#include "LinkedList.h"

LinkedList::LinkedList() : m_size(0)
{
    m_head = NULL;
}

LinkedList::~LinkedList()
{


}

void LinkedList::push_front(int value)
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

    return;
}

// Delete the first element in the list
void LinkedList::pop()
{
    int value = m_head->value;
    Node* new_head = m_head->prev;
    delete(m_head);
    m_head = new_head;
    m_size--;
    return;
}

int LinkedList::size() const 
{
    return m_size;
}

int LinkedList::front() const
{
    if(m_head != NULL)
    {
        return m_head->value;
    }
   
    exit(1);
}

