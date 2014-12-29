#include <cstddef>
#include <stdio.h>
#include "binaryTree.h"




BinaryTree:
BinaryTree() : head(NULL)
{

}


BinaryTree:
BinaryTree(Node* h) : head(h)
{

}


void BinaryTree:
insert(int value)
{
    if (head == NULL)
    {
        head = new Node();
        head->value = value;
        head->left = NULL;
        head->right = NULL;
        return;
    }

    Node* current = head;

    while(true)
    {
        if(current->value == value)
        {
            return;
        }

        nNode = new Node();
        nNode->value = value;
        nNode->right = NULL;
        nNode->left = NULL;

        if (current->value < value)
        {
            if (current->right == NULL)
            {
                current->right = nNode;
                return;
            }
            else
            {
                current = current->right;
            }
        }
        else
        {
            if (current->left == NULL)
            {
                current->left = nNode;
                return;
            }
            else
            {
                current = current->left;
            }
        }


    }
}


void BinaryTree:
remove(int value)
{
    if (head == NULL)
    {
        return;
    }


    Node* current = head;
    while (true)
    {

        if ( current->value == value)
        {

        }


        /*if(head == NULL)
        {
            return;
        }
        if(head->value == value)
        {
            return;
        }
        else if (head->value > value)
        {
            if(head->left == NULL)
            {
                return;
            }
            else
            {
                pop(value, head->left);
            }
        }
        else if (head->value <= value)
        {
            if(head->right == NULL)
            {
                return;
            }
            else
            {
                pop(value, head->right);
            }
        }
        */
    }


    int main(int argc, const char* argv[])
    {

        return 0;
    }
