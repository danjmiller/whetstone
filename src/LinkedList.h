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

   void push_front(int n);
   void pop();
   int size() const;
   int front() const;

private:
   Node* m_head;
   int m_size;
    
};
