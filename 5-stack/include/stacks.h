#ifndef STACKS
#define STACKS

#include <stack>
#include <algorithm>
using namespace std;


// For the following tasks manipulate the passed in stack.

template <typename T>
void push_elements(stack<T> &s, T arr[], size_t size) {
    // Insert the values from the array into the stack
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========
    for (size_t i = 0; i < size; ++i)
        s.push(arr[i]);
    // ====================================================
}

template <typename T>
T sum(stack<T> &s) {
    // Sum up all of the elements in the stack
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========
    stack<T> temp;  // Used as storage to traverse all elements of s
    T sum = s.top();
    temp.push(s.top());
    s.pop();

    // Pop all elements of s and add to accumulator
    while (!s.empty()) {
        sum += s.top();
        temp.push(s.top());
        s.pop();
    }

    // Recover all elements of s
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }

    return sum;
    // ====================================================
}

template <typename T>
void clear(stack<T> &s) {
    // Remove all elements from the stack
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========
    while (!s.empty())
    s.pop();
    // ====================================================
}

template <typename T>
void reverse(stack<T> &s) {
    // Reverse the elements of the stack
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========
    stack<T> temp;

    // Push all elements into temp stack. Creates reversed order in temp
    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }
    
    // Swap contents with temp
    s.swap(temp);
    // ====================================================
}

#endif

