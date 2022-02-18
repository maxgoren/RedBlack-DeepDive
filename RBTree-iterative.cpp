#include <iostream>
#include <climits>
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
        node(K k, V v, bool c, node* ll, node* rr)
        { key = k; val = v; color = c; left = ll; right = rr; }
        node(K k, V v)
        { key = k; val = v; left = nullptr; right = nullptr; color = red; }
        node()
        { color = red; right = left = nullptr; }
    };
    private:
    node *head, *z, *x, *p, *g, *gg; //head & z are sentinals, p, g, and gg are used
    node* rotate(K v, node* y)     //instead of internal parent pointers 
    {
        node *c, *gc;
        c = (v < y->key) ? y->left:y->right;
        if (v < c->key)
        {
            //rotate right
            gc = c->left; c->left = gc->right; gc->right = c;
        } else {
            //rotate left
            gc = c->right; c->right = gc->left; gc->left = c;
        }
        if (v < y->key) y->left = gc; else y->right = gc;
        return gc;
    }
    void split(K v)
    {
        x->color = red; x->left->color = black; x->right->color = black;
        if (p->color)
        {
            g->color = red;
            if (v < g->key != v < p->key) p = rotate(v, g);
            x = rotate(v, gg);
            x->color = black;
        }
    }
    void walk(node* h)
    {
        if (h == z) return;
        cout<<h->key;
        if (h->color) cout<<" Red.\n";
        else cout<<" Black.\n";
        walk(h->left);
        walk(h->right);
    }
    public:
    RBTree()
    {
        z = new node(INT_MAX, 0, black, nullptr, nullptr);
        z->left = z;
        z->right = z;
        head = new node(INT_MIN, 0, black, nullptr, z);
    }
    void insert(K key, V val)
    {
        x = head;
        p = x;
        g = x;
        while (x != z)
        {
            gg = g; g = p; p = x;
            x = (key < x->key) ? x->left:x->right;
            //split four nodes on way down the tree
            if (x->left->color && x->right->color)
                split(key);
        }
        x = new node(key, val, red, z, z);
        if (key < p->key) p->left = x;
        else p->right = x;
        split(key);
        head->right->color = black;
    }
    V find(K key)
    {
        x = head->right;
        while (x != z)
        {
            if (key == x->key)
                return x->info;
            
            x = (key < x->key) ? x->left:x->right;
        }
        return NULL;
    }
    V getMin()
    {
        x = head->right;
        while (x->left != z)
            x = x->left;
        return x->info;
    }
    V getMax()
    {
        x = head->right;
        while (x->right != z)
            x = x->right;
        return x->info;
    }
    void show()
    {
        walk(head->right);
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
