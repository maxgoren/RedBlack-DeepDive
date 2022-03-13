//based off cormen && STL implementation
//of Red/Black

#include <iostream>
using namespace std;

template <class K, class V>
class RedBlack {
    private:
    enum RedBl { Black = 0, Red = 1 };
    struct node {
        K key;
        V value;
        RedBl color;
        node *left, *right, * parent;
        node(K k, V v, node* ll, node* rr, node* pp)
        {
            left = ll; right = rr; parent = pp;
            color = Red; key = k; value = v;
        }
        node(K k, V v)
        {
            left = right = parent = nullptr;
            color = Red;
            key = k;
            value = v;
        }
        node()
        {
            left = right = parent = nullptr;
            color = Red;
        }
    };
    typedef node* nodeptr;
    nodeptr head, z;
    nodeptr& Parent(nodeptr h)
    {
        return h->parent;
    }
    nodeptr& Left(nodeptr h)
    {
        return h->left;
    }
    nodeptr& Right(nodeptr h)
    {
        return h->right;
    }
    RedBl& Color(nodeptr h)
    {
        return h->color;
    }
    nodeptr& Root()
    {
        return head->right;
    }
    bool isNil(nodeptr h)
    {
        if (h == nullptr)
            return true;
        if (h == z)
            return true;
        return false;
    }
    bool isRed(nodeptr h)
    {
        return isNil(h) ? false:(Color(h) == Red);
    }
    void insertRB(K key, V value)
    {
        nodeptr x = Root();
        nodeptr y = head;
        bool addLeft;
        while (!isNil(x))
        {
            y = x;
            x = (key < x->key) ? Left(x):Right(x);
        }
        x = new node(key, value, z, z, y);
        if (y == head)
        {
            cout<<"Setting Root.\n";
            head->right = x;
            Color(Right(head)) = Black;
            return;
        }
        if (key < y->key)
        {
            y->left = x;
        } else {
            y->right = x;
        }
        insertFix(addLeft, x);
    }
    void Lrotate(nodeptr X)
    {
        nodeptr Y = Right(X);
        Right(X) = Left(Y);
        if (!isNil(Left(Y)))
            Parent(Left(Y)) = X;
        Parent(Y) = Parent(X);
        if (X == Root())
            Root() = Y;
        else if (X == Left(Parent(X)))
            Left(Parent(X)) = Y;
        else
            Right(Parent(X)) = Y;
        Left(Y) = X;
        Parent(X) = Y;
    }
    void Rrotate(nodeptr X)
    {
        nodeptr Y = Left(X);
        Left(X) = Right(Y);
        if (!isNil(Right(Y)))
            Parent(Right(Y)) = X;
        Parent(Y) = Parent(X);
        if (X == Root())
            Root() = Y;
        if (X == Right(Parent(X)))
            Right(Parent(X)) = Y;
        else
            Left(Parent(X)) = Y;
        Right(Y) = X;
        Parent(X) = Y;
    }
    void insertFix(bool addLeft, nodeptr Y)
    {
        for (nodeptr X = Y; Color(Parent(X)) == Red; )
        {
            if (Parent(X) == Left(Parent(Parent(X))))
            {
                Y = Right(Parent(Parent(X)));
                if (Color(Y) == Red)
                {
                    Color(Parent(X)) = Black;
                    Color(Y) = Black;
                    Color(Parent(Parent(X))) = Red;
                    X = Parent(Parent(X));
                } else {
                    if (X == Right(Parent(X)))
                    {
                        X = Parent(X);
                        Lrotate(X);
                    }
                    Color(Parent(X)) = Black;
                    Color(Parent(Parent(X))) = Red;
                    Rrotate(Parent(Parent(X)));
                }
            } else {
                    Y = Left(Parent(Parent(X)));
                    if (Color(Y) == Red)
                    {
                        Color(Parent(X)) = Black;
                        Color(Y) = Black;
                        Color(Parent(Parent(X))) = Red;
                        X = Parent(Parent(X));
                    } else {
                        if (X == Left(Parent(X)))
                        {
                            X = Parent(X);
                            Rrotate(X);
                        }
                        Color(Parent(X)) = Black;
                        Color(Parent(Parent(X))) = Red;
                        Lrotate(Parent(Parent(X)));
                    }
                }
            }
        Color(Root()) = Black;
    }
    void preorder(nodeptr h)
    {
        if (!isNil(h))
        {
            cout<<h->key<<" ";
            preorder(Left(h));
            preorder(Right(h));
        }
    }
    public:
    RedBlack()
    {
        //head = new node();
        z = new node();
        z->left = z->right = z;
        z->parent = z;
        z->color = Black;
        //head->parent = head;
        //head->right = z; head->left = z;
        head = z;
    }
    void insert(K key, V value)
    {
        insertRB(key, value);
    }    
    void show()
    {
        preorder(Root());
        cout<<endl;
    }
};

int main()
{
    RedBlack<char, char> rb;
    string str = "ASEARCHINGEXAMPLE";
    for (auto c : str)
        rb.insert(c, c);

    rb.show();
    return 0;
}