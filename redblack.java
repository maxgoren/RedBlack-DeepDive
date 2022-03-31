public class redblack<K extends Comparable, V> {
    class Node {
        private K key;
        public Node left;
        public Node right;
        private Boolean color;
        Node(K k, Boolean c, Node ll, Node rr)
        {
            this.key = k;
            this.color = c;
            this.left = ll;
            this.right = rr;
        }
        public void setKey(K k)
        {
            this.key = k;
        }
        public K Key()
        {
            return this.key;
        }
        public void setColor(Boolean c)
        {
            this.color = c;
        }
        public Boolean color()
        {
            return this.color;
        }
    };

    private Node head, z, x, p, g, gg;
    
    private Boolean isRed(Node h)
    {
        return (h == null) ? false:(h.color() == true);
    }

    //Constructor
    redblack(K dataMin, K dataMax)
    {
        z = new Node(dataMax, false, null, null);
        z.left = z; z.right = z;
        head = new Node(dataMin, false, z, z);
    }
    
    //insert function
    public void insert(K Key)
    {
        x = head; p = x; g = p;
        while (x != z)
        {
            gg = g; g = p; p = x;
            if (Key.compareTo(x.Key()) < 0)
            { 
                x = x.left;
            } else {
                x =  x.right;
            }
            if (isRed(x.left) && isRed(x.right))
                split(Key);
        }
        x = new Node(Key, true, z, z);
        if (Key.compareTo(p.Key()) < 0)
        {
            p.left = x;
        } else {
            p.right = x;
        }
        split(Key);
        head.right.setColor(false);
    }
    //rebalancing
    private Node rotate(K key, Node y)
    {
        Node c, gc;
        c = (key.compareTo(y.Key()) < 0) ? y.left:y.right;
        if (key.compareTo(c.Key()) < 0)
        {
            gc = c.left; c.left = gc.right; gc.right = c;
        } else {
            gc = c.right; c.right = gc.left; gc.left = c;
        }
        if (key.compareTo(y.Key()) < 0) y.left = gc; else y.right = gc;
        return gc;
    }
    //rebalancing
    private void split(K key)
    {
        x.setColor(true);
        x.left.setColor(false);
        x.right.setColor(false);
        if (isRed(p))
        {
            g.setColor(true);
            if (key.compareTo(p.Key()) < 0 != key.compareTo(g.Key()) < 0) p = rotate(key, g);
            x = rotate(key, gg);
            x.setColor(false);
        }
    }

    /* Tree search functions */
    public K findMin()
    {
        x = head.right;
        while (x.left != z)
        {
            x = x.left;
        }
        return x.Key();
    }
    public K findMax()
    {
        x = head.right;
        while (x.right != z)
        {
            x = x.right;
        }
        return x.Key();
    }
    public K find(K key)
    {
        x = head.right;
        while (x != z)
        {
            if (key.compareTo(x.Key()) == 0)
                return x.Key();
            x = (key.compareTo(x.Key()) < 0) ? x.left:x.right;
        }
        return null;
    }
    /* Tree Walking Functions */
    private void preorder(Node h)
    {
        if (h == z)
            return;
        System.out.print(h.Key() + " ");
        preorder(h.left);
        preorder(h.right);
    }
    private void inorder(Node h)
    {
        if (h == z) 
            return;
        
        inorder(h.left);
        System.out.print(h.Key() + " ");
        inorder(h.right);    
    }
    public void show()
    {
        preorder(head.right);
        System.out.print("\n");
    }
    public void sort()
    {
        inorder(head.right);
        System.out.print("\n");
    }
    public static void main(String args[])
    {
        redblack<Character, Integer> rb = new redblack('A', 'Z');
        String str = "ASEARCHINGEXAMPLE";
        for (int i = 0; i < str.length(); i++)
        {
            rb.insert(Character.valueOf(str.charAt(i)));
        }
        rb.show();
        rb.sort();
        System.out.println(rb.findMin());
        System.out.println(rb.findMax());
        System.out.println(rb.find(Character.valueOf('L')));
    }
}