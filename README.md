# A deep dive into Red/Black Trees

In taking a closer look at the ubiquious red/black tree ive implemented several different versions
as described in different books/resources on Data Strucutres and Algorithms.

So Far:
```
RBTree-iterative.cpp - Iterative version of Red/Black tree from Sedgewicks Algorithms in C++ 1st. ed.
                       This version uses external parent/ancestor pointers, as well as head/nil sentinel nodes.
                       
RBTree.cpp - Recursive implentation of Red/Black tree from Sedgewicks Algorithms in C++ 3rd. ed.

LLRBTree.cpp - Recursive implementation of Left Leaning Red/Black tree from Sedgewicks 2008 paper. A greatly simplified
              method of implementing this somewhat cumbersome data structure, representing a 30+ year evolution of the concept
               as present by professor sedgewick.
```

Works In Progess:
```
CLRS-RB.cpp - as presented in Cormen et. al.'s "Introduction to algorithms". sys/tree.h on bsd systems and linux/types/tree.h
                  in the linux kernel are rather faithful implementations of this version, albeit in C
```

Coming Eventually
```
The highly OOP-centric implementation present in Goodrich and Tamassia's "Data Structures and Algorithms in C++". This is a VERY different
take compared to the other appraoches commonly seen. Interestingly i believe this is the version the C++ STL version is based on, though
i could be wrong.
```
