

class  Node
{

public:
    Node(int value);

    bool add(int value);
    bool find(int val);
    Node* remove(int val, Node* parent);

    int minValue();

    Node* left;
    Node* right;
    int value;

};


class BinaryTree
{

public:
    BinaryTree();
    BinaryTree(Node* head);

    bool insert(int value);
    bool find(int value);
    bool remove(int value);

    Node* findMin(Node* n);
    
    int size;

private:
    Node* root;


};

