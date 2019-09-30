
#include "gtest/gtest.h"
#include "lists.h"
#include <list>
#include <algorithm>

list<int> copy_list{1, 2, 3, 4, 5};
ListQuestions<int> tasks(copy_list);

TEST(LISTS, Push_Front) {
    tasks.push_front_elements();
    EXPECT_EQ(tasks.get_list().size(), 8);
}

TEST(LISTS, Delete_Element) {
    tasks.delete_element();
    list<int> temp = tasks.get_list();
    list<int>::iterator it = temp.begin();
    for (size_t i = 0; i < 2; i++) it++;
    EXPECT_EQ(*it, 1);
}

TEST(LISTS, Get_Element) {
    int x = 4;
    EXPECT_EQ(*(tasks.get_element(x)), 4);

}

TEST(LISTS, Pop_Front) {
    tasks.pop_front_elements();
    EXPECT_EQ(tasks.get_list().size(), 5);
}

TEST(LISTS, Sum) {
    EXPECT_EQ(tasks.sum(), 15);
}

TEST(LISTS, Swap) {
    tasks.swap_elements();
    EXPECT_EQ(tasks.get_list().front(), 5);
    EXPECT_EQ(tasks.get_list().back(), 1);
}

TEST(LISTS, Insert_Elements) {
    int x = 5;
    tasks.insert_elements(x);
    list<int> temp = tasks.get_list();
    list<int>::iterator it = temp.begin();
    for (size_t i = 0; i < 1; i++) it++;
    EXPECT_EQ(*it, 2);
    for (size_t i = 0; i < 2; i++) it++;
    EXPECT_EQ(*it, 3);
}

TEST(LISTS, Sort) {
    tasks.sort();
    ASSERT_TRUE(is_sorted(tasks.get_list().begin(), tasks.get_list().begin()));
}

TEST(LISTS, Clear) {
    tasks.clear_elements();
    EXPECT_EQ(tasks.get_list().size(), 0);
}
