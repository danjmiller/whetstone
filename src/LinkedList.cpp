#include <cstddef>
#include <stdio.h>
#include <iostream>

#include "LinkedList.h"

LinkedList::LinkedList() : m_size(0)
{
    m_head = NULL;
    m_tail = NULL;
}

LinkedList::~LinkedList()
{


}

void LinkedList::insertBeginning(Node* newNode)
{
    
    if(m_head == NULL) //empty list
    {
        m_head = newNode;
        m_tail = newNode;
        m_head->next = NULL;
        m_head->prev = NULL;
        m_size++;
    }
    else if (m_head != newNode)
    {
        //TODO find the node in case it is somewhere else in the list
        newNode->next = m_head;
        newNode->prev = NULL;
        m_head->prev = newNode;
        m_head = newNode;
        m_size++;
    }
    else if (m_head == newNode)
    {
        //No-Op node is already in the list
        std::cout << "Node already in list, Skipping" << std::endl;
    }

    return;
}

void LinkedList::insertEnd(Node* newNode)
{
    if(m_tail == NULL) //empty list
    {
        m_head = newNode;
        m_tail = newNode;
        m_tail->next = NULL;
        m_tail->prev = NULL;
        m_size++;
    }
    else if (m_head != newNode)
    {
        //TODO find the node in case it is somewhere else in the list
        newNode->prev = m_tail;
        newNode->next = NULL;
        m_tail->next  = newNode;
        m_tail = newNode;
        m_size++;
    }
    else if (m_head == newNode)
    {
        //No-Op node is already in the list
        std::cout << "Node already in list, Skipping" << std::endl;
    }

    return;   
}

void LinkedList::insertBefore(Node *n, Node* newNode)
{
    if( n == NULL )
    {
        std::cout << "NULL Target, skipping Insert" << std::endl;
    }

    if(newNode == NULL)
    {
        std::cout << "Cannot Insert a Null Node, Skipping" << std::endl;
    }

    Node* tmp = n->prev;
    n->prev = newNode;
    newNode->prev = tmp;
    newNode->next = n;
    m_size++;

    return;

}


void LinkedList::insertAfter(Node *n, Node* newNode)
{
    if( n == NULL )
    {
        std::cout << "NULL Target, skipping Insert" << std::endl;
    }

    if(newNode == NULL)
    {
        std::cout << "Cannot Insert a Null Node, Skipping" << std::endl;
    }

    Node* tmp = n->next;
    n->next = newNode;
    newNode->next = tmp;
    newNode->prev = n;
    m_size++;

    return;
}

int LinkedList::size() const 
{
    return m_size;
}


Node* LinkedList::find(Node* n)
{
    if(n == NULL || m_head == NULL || m_size == 0)
    {
        return NULL;
    }

    Node* current = m_head;
   
    while(current != NULL)
    {
        if( n == current )
        {
            return n;
        }

        current = current->next;
    }

    return NULL;
}

std::vector<Node*> LinkedList::dumpList()
{
    std::vector<Node*> vec;
    
    if( m_size == 0 || m_head == NULL)
    {
        return vec;
    }

    Node* current = m_head;
   
    while(current != NULL)
    {
        vec.push_back(current);
        current = current->next;
    }
    
    return vec;
}


