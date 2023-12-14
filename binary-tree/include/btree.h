struct Node
{
    int key;
    Node *parent;
    Node *left;
    Node *right;
    Node()
    {
        parent = left = right = nullptr;
    }
    Node(int k) : key(k)
    {
        parent = left = right = nullptr;
    }
};

class BST
{
private:
    Node *root;

public:
    BST();
    BST(int key);
};