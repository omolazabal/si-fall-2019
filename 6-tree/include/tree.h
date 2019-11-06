
#ifndef RECURSION_H
#define RECURSION_H

#include <iostream>
using namespace std;

template <typename K>
class Node {
public:
    K key;
    Node<K> *left;
    Node<K> *right;
    Node() { left = right = nullptr; }
};

template <typename K>
void insert(Node<K> *&ptr, K key) {
    if (ptr == nullptr) {
        ptr = new Node<K>;
        ptr->key = key;
    }
    else {
        if (key < ptr->key)
            insert(ptr->left, key);
        else if (key > ptr->key)
            insert(ptr->right, key);
    }
}


// For the following tasks manipulate the passed in stack.

template <typename K>
K& max(Node<K> *ptr) {
    // Return the max key in the tree
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========
    K key = 0;
    return key;


    // ====================================================
}

template <typename K>
size_t count_leaf_nodes(Node<K> *ptr) {
    // Return the number of leaf nodes in the tree
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========
    return 0;


    // ====================================================
}


template <typename K>
K sum(Node<K> *ptr) {
    // Find the sum of the BST
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========
    return 0;



    // ====================================================
}

// ===== END TODO ===== //

#endif
