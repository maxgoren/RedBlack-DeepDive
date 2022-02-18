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
        node* parent;
        node(K k, V v)
        { key = k; val = v; left = nullptr; right = nullptr; parent = nullptr; color = red; }
        node()
        { color = red; parent = nullptr; right = left = nullptr; }
    };
    node *nil, *root;
    void right_rotate(node* x)
    {
        node* y = x->left;
        x->left = y->right;
        if (y->left != nil)
            y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nil)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }
    void left_rotate(node* x)
    {
        node* y = x->right;
        x->right = y->left;
        if (y->right != nil)
            y->right->parent = x;
        y->parent = x->parent;
        if (x->parent == nil)
            root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;
        y->right = x;
        x->parent = y;
    }
    void rb_fix_insert(node* z)
    {
        node* y;
        while (z->parent->color == red)
        {
            cout<<"z's parent color is red.\n";
            if (z->parent == z->parent->parent->left)
            {
                cout<<"z falls on the left.\n";
                y = z->parent->parent->right;
                if (y->color == red)
                {
                    z->parent->color = black;
                    y->color = black;
                    z->parent->parent->color = red;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right)
                    {
                        z = z->parent;
                        cout<<"Left Rotate.\n";
                        left_rotate(z);
                    }
                    z->parent->color = black;
                    z->parent->parent->color = red;
                    cout<<"right rotate.\n";
                    right_rotate(z->parent->parent);
                }
            } else {
                cout<<"z falls on right right.\n";
                y = z->parent->parent->left;
                if (y->color == red)
                {
                    z->parent->color = black;
                    y->color = black;
                    z->parent->parent->color = red;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left)
                    {
                        z = z->parent;
                        cout<<"right rotate.\n";
                        right_rotate(z);
                    }
                    z->parent->color = black;
                    z->parent->parent->color = red;
                    cout<<"left rotate.\n";
                    left_rotate(z->parent->parent);
                }
            }
        }
        root->color = black;
    }
    void walk(node* h)
    {
        if (h == nil) return;
        cout<<h->key;
        if (h->color) cout<<" Red.\n";
        else cout<<" Black.\n";
        walk(h->left);
        walk(h->right);
    }
    public:
    RBTree()
    {
        nil = new node;
        nil->left = nil;
        nil->right = nil;
        nil->parent = nil;
        nil->color = black;
        root = nil;
    }
    void insert(K key, V val)
    {
        node *x, *y, *z;
        y = nil;
        x = root;
        while (x != nil)
        {
            y = x;
            x = (key < x->key) ? x->left:x->right;
        }
        z = new node(key, val);
        z->parent = y;
        z->left = nil;
        z->right = nil;
        z->color = red;
        if (y == nil)
        {
            root = z;
            return;
        } else if (key < x->key) {
            x->left = z;
        } else {
            x->right = z;
        }
        cout<<"Fixing up.\n";
        rb_fix_insert(z);
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
        cout<<"Inserting: "<<c<<"\n";
        redblack.insert(c, c);
    }
    redblack.show();
    return 0;
}