
#include "gtest/gtest.h"
#include "tree.h"

using namespace std;

//                               
//        The Binary Search Tree
//
//                15
//              /    \
//            8       20
//          /   \       \
//        2     10      36
//


void init_bst(Node<int> *&root) {
    insert(root, 15);
    insert(root, 8);
    insert(root, 20);
    insert(root, 2);
    insert(root, 10);
    insert(root, 36);
}

TEST(Recursion, Max) {
    Node<int>* root = nullptr;
    init_bst(root);
    EXPECT_EQ(max(root), 36);
}

TEST(Recursion, Count_Leaf_Nodes) {
    Node<int>* root = nullptr;
    init_bst(root);
    EXPECT_EQ(count_leaf_nodes(root), 3);
}

TEST(Recursion, Sum) {
    Node<int>* root = nullptr;
    init_bst(root);
    EXPECT_EQ(sum(root), 91);
}

