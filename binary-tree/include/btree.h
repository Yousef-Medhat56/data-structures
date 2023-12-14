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

    void addLeafPrivate(int key, Node *&node);
    void printInOrderPrivate(Node *&node);
    void destroyTree(Node *&node);

public:
    BST();
    BST(int key);
    void addLeaf(int key);
    void printInOrder();
    ~BST();
};