#include <vector>

struct  Node
{
    Node* next;
    Node* prev;
    int value;
};


class LinkedList{

public:
   LinkedList();
   ~LinkedList();

   void insertBeginning(Node* newNode);
   void insertEnd(Node* newNode);

   void insertBefore(Node* n, Node* newNode);
   void insertAfter(Node* n, Node* newNode);

   void remove(Node* n);
   Node* find(Node* n);

   int size() const;

   std::vector<Node*> dumpList();

private:    
   Node* m_head;
   Node* m_tail;
   int m_size;
    
};
