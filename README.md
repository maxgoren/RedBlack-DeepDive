# A deep dive into Red/Black Trees

In taking a closer look at the ubiquious red/black tree ive implemented several different versions
as described in different books/resources on Data Strucutres and Algorithms. I'm focusing on the different
approaches to node insertion, as deletion from Red/Black trees is incredibly complex. The exception
being Left Leaning red black trees, which can take advantage of a version of hibbard deletion which takes
the necessary recoloring into consideration.

So Far:
```
RBTree-iterative.cpp - Iterative version of Red/Black tree from Sedgewicks Algorithms in C++ 1st. ed.
                       This version uses external parent/ancestor pointers, as well as head/nil sentinel nodes.
                       
RBTree.cpp - Recursive implentation of Red/Black tree from Sedgewicks Algorithms in C++ 3rd. ed.

LLRBTree.cpp - Recursive implementation of Left Leaning Red/Black tree from Sedgewicks 2008 paper. A greatly simplified
              method of implementing this somewhat cumbersome data structure, representing a 30+ year evolution of the concept
               as present by professor sedgewick.

RedBlack-CLRS.cpp - as presented in Cormen et. al.'s "Introduction to algorithms". sys/tree.h on bsd systems and linux/types/tree.h
                  in the linux kernel are rather faithful implementations of this version, albeit in C, so i decided to give a 
                  shot at it in C++ this would not have gotten completed without thumbing through p.j. laugers "The C++ Standard Template Library"
                  I'd like to point out that this code is almost twice as long as the next longest implementation in terms of LOC. 
                  IDK why cormen choose to implement this data structure the way he did, but its ugly, and complicated for no good reason
                  and somehow has become "the gold standard" in red/black tree implementation. perhaps i'm missing something...
```

Coming Eventually
```
The highly OOP-centric implementation present in Goodrich and Tamassia's "Data Structures and Algorithms in C++". This is a VERY different
take compared to the other appraoches commonly seen. Interestingly i believe this is the version the C++ STL version is based on, though
i could be wrong.
```
