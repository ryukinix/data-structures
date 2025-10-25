<a href="https://github.com/ryukinix/data-structures/actions/workflows/ci.yml">
    <img alt="GitHub Actions" src="https://github.com/ryukinix/data-structures/actions/workflows/ci.yml/badge.svg" />
</a>

# Data Structures Lerax

## Introduction

This project is a collection of common data structures, sorting, and
search algorithms implemented in C. It was developed initially as part of the
Data Structures course at Federal University of Ceará (UFC), Sobral campus,
taught by Professor Jarbas Joaci de Sá in 2017.2. This work has been
continued with the master degree lectures of course [CT-234] Data Structures &
Algorithms & Complexity Analysis from Instituto Tecnológico de
Aeronáutica (ITA) in 2025.2 by Professor Carlos Alberto Alonso Sanches .

Source: [github.com](https://github.com/ryukinix/data-structures).

The main goal of this repository is to provide a simple and clear
implementation of these data structures and algorithms, as well as to
serve as a learning resource for students and developers.

[CT-234]: https://www.comp.ita.br/~alonso/ensino.html


## Getting started

You can generate a static and dynamic library by cloning the project
and running:

```
make lib
```

It will create the directory lib/ with ds-lerax.so and ds-lerax.h and
headers. You can install it in your system as:

```
sudo make install
```

Once installed, you can include in your program like this:

```c
#include <ds-lerax/ds-lerax.h>

int main(void) {
    List* l = list_init(
        5,
        5, 2, 3, 4, 1
    );
    list_println(l);
    list_sort(&l);
    list_println(l);
    list_free(l);
}
```

Compile and run the program by linking with `ds-lerax` lib like this:

```
gcc -o main main.c -lds-lerax -lm  && ./main
```

You should got something like this in the terminal.

```
[5, 2, 3, 4, 1]
[1, 2, 3, 4, 5]
```

## Data Structures

The following data structures are implemented in this project:

- **Singly Linked List:** A linear data structure where each element is a separate object. Each element (we will call it a node) of a list is comprising of two items - the data and a reference to the next node.
  - See header file: [src/list/single/list.h](src/list/single/list.h)
- **Doubly Linked List:** A linear data structure where each node has a pointer to the next node and also to the previous node.
  - See header file: [src/list/double/list-double.h](src/list/double/list-double.h)
- **Circular Linked List:** A linked list where all nodes are connected to form a circle.
  - See header file: [src/list/circular/list-circular.h](src/list/circular/list-circular.h)
- **Stack:** A linear data structure which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out).
  - See header file: [src/stack/stack.h](src/stack/stack.h)
- **Queue:** A linear structure which follows a particular order in which the operations are performed. The order is First In First Out (FIFO).
  - See header file: [src/queue/queue.h](src/queue/queue.h)
- **Priority Queue:** An abstract data type similar to a regular queue or stack data structure, but where additionally each element has a "priority" associated with it.
  - See header file: [src/pqueue/pqueue.h](src/pqueue/pqueue.h)
- **Binary Tree:** A tree data structure in which each node has at most two children, which are referred to as the left child and the right child.
  - See header file: [src/tree/binary-tree.h](src/tree/binary-tree.h)
- **Binary Search Tree (BST):** A node-based binary tree data structure which has the following properties: The left subtree of a node contains only nodes with keys lesser than the node’s key. The right subtree of a node contains only nodes with keys greater than the node’s key. The left and right subtree each must also be a binary search tree.
  - See header file: [src/tree/bst/bst.h](src/tree/bst/bst.h)
- **AVL Tree:** A self-balancing binary search tree. It was the first such data structure to be invented.
  - See header file: [src/tree/avl/avl.h](src/tree/avl/avl.h)
- **Hash Table:** A data structure that implements an associative array abstract data type, a structure that can map keys to values.
  - See header file: [src/hash-table/hash-table.h](src/hash-table/hash-table.h)
- **Set:** An abstract data type that can store unique values, without any particular order.
  - See header file: [src/set/set.h](src/set/set.h)
- **Matrix:** A rectangular array or table of numbers, symbols, or expressions, arranged in rows and columns.
  - See header file: [src/matrix/matrix.h](src/matrix/matrix.h)
- **Point:** A basic geometric entity representing a location in a coordinate system.
  - See header file: [src/point/point.h](src/point/point.h)
- **Graph:** A non-linear data structure consisting of a set of vertices and a set of edges that connect the vertices. This implementation includes algorithms for traversing the graph, such as Breadth-First Search (BFS) and Depth-First Search (DFS).
  - See header file: [src/graph/graph.h](src/graph/graph.h)

## Sorting Algorithms

The following sorting algorithms are implemented in this project:

- **Bubble Sort:** A simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.
- **Insertion Sort:** A simple sorting algorithm that builds the final sorted array (or list) one item at a time.
- **Selection Sort:** A simple sorting algorithm that repeatedly finds the minimum element from the unsorted part and puts it at the beginning.
- **Merge Sort:** An efficient, general-purpose, comparison-based sorting algorithm.
- **Quick Sort:** An efficient sorting algorithm, serving as a systematic method for placing the elements of an array in order.
- **Heap Sort:** A comparison-based sorting algorithm. Heapsort can be thought of as an improved selection sort.
- **Radix Sort:** A non-comparative integer sorting algorithm that sorts data with integer keys by grouping keys by the individual digits which share the same significant position and value.

See header file for all sorting algorithms: [src/sort/sort.h](src/sort/sort.h)

## Search Algorithms

The following search algorithms are implemented in this project:

- **Naive Search:** A straightforward string searching algorithm that checks all possible placements of a pattern in a text.
- **Knuth-Morris-Pratt (KMP) Search:** An efficient string-searching algorithm that avoids re-examining characters that have already been matched.
- **Boyer-Moore Search:** An efficient string-searching algorithm that skips characters in the text by using information gained from mismatches.
- **Karp-Rabin Search:** A string-searching algorithm that uses hashing to find any one of a set of pattern strings in a text.

See header file for all search algorithms: [src/search/search.h](src/search/search.h)

## Author

Manoel Vilela
