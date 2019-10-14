
#include "gtest/gtest.h"
#include "stacks.h"
#include <stack>
#include <algorithm>

using namespace std;

TEST(STACKS, Push_Elements) {
    stack<int> s;
    int arr[] = {1, 2, 3, 4};
    push_elements(s, arr, 4);

    if (!s.empty()) {
        EXPECT_EQ(s.top(), 4);
        s.pop();
        EXPECT_EQ(s.top(), 3);
        s.pop();
        EXPECT_EQ(s.top(), 2);
        s.pop();
        EXPECT_EQ(s.top(), 1);
        s.pop();
    }
    else
    {
        ASSERT_TRUE(false);
    }
    
}

TEST(STACKS, Reverse) {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    reverse(s);

    EXPECT_EQ(s.top(), 1);
    s.pop();
    EXPECT_EQ(s.top(), 2);
    s.pop();
    EXPECT_EQ(s.top(), 3);
    s.pop();
}

TEST(STACKS, Sum) {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    EXPECT_EQ(sum(s), 6);
}

TEST(STACKS, Clear) {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    clear(s);

    EXPECT_EQ(s.size(), 0);
}
