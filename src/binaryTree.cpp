#include <cstddef>
#include <stdio.h>
#include <iostream>
#include "binaryTree.h"


using namespace std;


Node::Node(int val) : value(val), left(NULL), right(NULL)
{

}

bool Node::add(int val)
{
    if (val == value)
    {
        //Unique elements only
        return false;
    }
    else if(val < value)
    {
        if (left == NULL)
        {
            left = new Node(val);
            return true;
        }
        else
        {
            return left->add(val);
        }
    }
    else if (val > value)
    {
        if (right == NULL)
        {
            right = new Node(val);
            return true;
        }
        else
        {
            return right->add(value);
        }
    }
    
    //Should never happen
    return false;
}

bool Node::find(int val)
{
    if ( val == value)
    {
        return true;
    }
    else if(val < value)
    {
        if(left == NULL)
        {
            return false;
        }
        else
        {
            return left->find(val);
        }
    }
    else if(val > value)
    {
        if (right == NULL)
        {
            return false;
        }
        else
        {
            return right->find(val);
        }
    }

    return false;
}


Node* Node::remove(int val, Node* parent)
{
    if (val < value)
    {
        if(left != NULL)
        {
            return left->remove(value, this);
        }
        else
        {
            return NULL;
        }
    }
    else if (val > value)
    {
        if (right != NULL)
        {
            return right->remove(value,this);
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        if (left != NULL && right != NULL)
        {
            value = right->minValue();
            return right->remove(value, this);
        }
        else if( parent->left == NULL)
        {
            parent->left = (left != NULL) ? left : right;
            return this;
        }
        else if(parent->right == this)
        {
            parent->right = (left != NULL) ? left : right;
            return this;
        }
    }



}

int Node::minValue()
{
    if (left == NULL)
    {
        return value;
    }
    else
    {
        return left->minValue();
    }
}


BinaryTree::BinaryTree() : root(NULL)
{

}


BinaryTree::BinaryTree(Node* h) : root(h)
{

}


bool BinaryTree:: find(int val)
{
    if(root == NULL)
    {
        return false;
    }
    else
    {
        return root->find(val);
    }
}





bool BinaryTree::insert(int value)
{
  
    if (root == NULL)
    {
        root = new Node(value);
        return true;
    }
    else 
    {
        return root->add(value);
    }



}

Node* BinaryTree::findMin(Node* n)
{
    if(n->left == NULL)
    {    
        return NULL;
    }
    else
    {
        return findMin(n->left);
    }

    
  
    cout << "WARNING: Unexpected Behavior" << endl;
    return NULL;
}


bool BinaryTree::remove(int val)
{
    if ( root == NULL)
    {
        return false;
    }
    else 
    {
        if ( root->value == val)
        {
            Node* tmpRoot = new Node(0);
            tmpRoot->left = root;
            Node* removed = root->remove(val, tmpRoot);
            root = tmpRoot->left;
            
            if(removed != NULL)
            {
                delete removed;
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            Node* removed = root->remove(val, NULL);
            
            if(removed != NULL)
            {
                delete removed;
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
