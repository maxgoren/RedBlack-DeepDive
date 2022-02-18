#include <iostream>
using namespace std;

template <typename K, typename V>
class LLRBTree {
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
        node* x = h->right; h->right = x->left; x->left = h; x->color = h->color; h->color = red; h = x;
    }
    void rotR(node*& h)
    { 
        node* x = h->left; h->left = x->right; x->right = h; x->color = h->color; h->color = red; h = x;
    }
    bool isRed(node* h)
    {
        if (h == nullptr) return false;
        return (h->color == red);
    }
    void LLRBInsert(node*& h, K key, V val)
    {
        if (h == nullptr)
        {
            h = new node(key, val);
            return;
        }
        if (key < h->key)
        {
            LLRBInsert(h->left, key, val);
        } else {
            LLRBInsert(h->right, key, val);
        }
        if (isRed(h->right) && !isRed(h->left))
        {
            rotL(h);
        }
        if (isRed(h->left) && isRed(h->left->left))
        {
            rotR(h);
        }
        if (isRed(h->right) && isRed(h->left))
        {
            h->color = !h->color;
            h->left->color = !h->left->color;
            h->right->color = !h->right->color;
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
    LLRBTree()
    {
        root = nullptr;
    }
    void insert(K key, V val)
    {
        LLRBInsert(root, key, val);
        root->color = black;
    }
    void show()
    {
        walk(root);
    }
};

int main()
{
    LLRBTree<char, char> redblack;
    string str = "ASEARCHINGEXAMPLE";
    for (auto c : str)
    {
        redblack.insert(c, c);
    }
    redblack.show();
    return 0;
}
