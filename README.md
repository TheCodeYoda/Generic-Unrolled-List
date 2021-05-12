# Generic Programming Project: Unrolled Linked List

An Unrolled Linked List is a cache friendly list which thereby increases the cache performance by storing multiple elements per each node.
To optimize the fetching process in this kind of a list, the number of array elements in each node is fixed with respect to the cache line size or a multiple of it so that when a program accesses some data from the memory, it pulls the entire page and is now more likely to have obtained the desired element involving a considerably lesser cache misses, making it faster than a regular linked list by a certain factor, w.r.t access.

This project  covers the implementation of suitable member functions and a bidirectional iterator compatible with the STL Library to assist the operations on the unrolled linked list. The unrolled list is made generic in terms of support for different data types of the data stored and usage with the STL library.

## Dependencies and Build

No dependencies

Build debug mode:
```
make -j8
```

Build release mode:
```
make mode=release -j8
```

## Run
```
./gp_project
```
