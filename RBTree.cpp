#include <iostream>
using namespace std;

template <class K, class V>
class RBTree {
    protected:
    static const bool red = true;
    static const bool black = false;
    struct node {
        K key;
        V val;
        bool color;
        node* left;
        node* right;
        node(K k, V v)
        { key = k; val = v; left = nullptr; right = nullptr; color = red; }
        node()
        { color = red; right = left = nullptr; }
    };
    private:
    node* root;
    void rotL(node*& h)
    {
        node* x = h->right; h->right = x->left; x->left = h; h = x;
    }
    void rotR(node*& h)
    { 
        node* x = h->left; h->left = x->right; x->right = h; h = x;
    }
    bool isRed(node* h)
    {
        if (h == nullptr) return false;
        return (h->color == red);
    }
    void RBInsert(node*& h, K key, V val, bool sw)
    {
        if (h == nullptr)
        {
            h = new node(key, val);
            return;
        }
        //split any 4 nodes;
        if (isRed(h->left) && isRed(h->right))
        {
            h->color = red;
            h->left->color = black;
            h->right->color = black;
        }
        if (key < h->key)
        {
            RBInsert(h->left, key, val, false);
            if (isRed(h) && isRed(h->left) && sw) rotR(h);
            if (isRed(h->left) && isRed(h->left->left))
            {
                rotR(h);
                h->color = black; h->right->color = red;
            }
        } else {
            RBInsert(h->right, key, val, true);
            if (isRed(h) && isRed(h->right) && !sw) rotL(h);
            if (isRed(h->right) && isRed(h->right->right))
            {
                rotL(h);
                h->color = black;
                h->left->color = red;
            }
        }
    }
    void walk(node* h)
    {
        if (h == nullptr) return;
        cout<<h->key;
        if(isRed(h)) cout<<" Red.\n";
        else cout<<" Black.\n";
        walk(h->left);
        walk(h->right);
    }
    public:
    RBTree()
    {
        root = nullptr;
    }
    void insert(K key, V val)
    {
        RBInsert(root, key, val, false);
        root->color = black;
    }
    void show()
    {
        walk(root);
    }
};

int main()
{
    RBTree<char, char> redblack;
    string str = "ASEARCHINGEXAMPLE";
    for (auto c : str)
    {
        redblack.insert(c, c);
    }
    redblack.show();
    return 0;
}