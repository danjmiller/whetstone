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

   bool push(int n);
   int pop();

   int size() const;
private:
   Node* m_head;
   int m_size;
    
};
