

struct  Node
{
    Node* left;
    Node* right;
    int value;
};


class BinaryTree
{

public:
    BinaryTree();
    BinaryTree(Node* head);
    ~BinaryTree();

    void insert(int value);
    void delete(int value);


private:
    Node head;

};

