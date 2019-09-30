
#include "gtest/gtest.h"
#include "singly_linked_list.h"

TEST(Singly_Linked_List, Clear) {
    SinglyLinkedList<int> list;

    list.prepend(1);
    list.prepend(2);
    list.prepend(3);
    list.clear();

    ASSERT_TRUE(list.empty());
}

TEST(Singly_Linked_List, Size) {
    SinglyLinkedList<int> list;

    list.prepend(1);
    list.prepend(2);
    list.prepend(3);

    EXPECT_EQ(list.size(), 3);
}

TEST(Singly_Linked_List, At) {
    SinglyLinkedList<int> list;

    list.prepend(1);
    list.prepend(2);
    list.prepend(3);

    EXPECT_EQ(list.at(1), 2);
}

TEST(Singly_Linked_List, Swap_Head_And_Tail_Nodes) {
    SinglyLinkedList<int> list;

    list.prepend(1);
    list.prepend(2);
    list.prepend(3);

    list.swap_head_tail();
    EXPECT_EQ(list.front(), 1);
    EXPECT_EQ(list.back(), 3);
}

