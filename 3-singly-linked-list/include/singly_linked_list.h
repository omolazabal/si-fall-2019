
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdexcept>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next;
    Node() = delete;  // No default constructor
    Node(const T &element) : data(element), next( nullptr ) {}
};

template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    bool empty();
    void prepend(const T&);
    void append(const T&);
    void pop_front();

    T& front();
    T& back();

    void clear();
    size_t size();
    T& at(size_t);
    void swap_head_tail();
};

template <typename T>
void SinglyLinkedList<T>::clear() {
    // Delete every node in the linked list.
    // Utilize stdexcept to handle edge cases.
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========
    while (!empty())
        pop_front();
    // ====================================================
}

template <typename T>
size_t SinglyLinkedList<T>::size() {
    // Return the number of nodes in the linked list.
    // Utilize stdexcept to handle edge cases.
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========
    if (empty())
        throw length_error("empty list");
    size_t counter = 0;
    for (Node<T> *i = head; i != nullptr; i = i->next)
        counter++;
    return counter;
    // ====================================================
}

template <typename T>
T& SinglyLinkedList<T>::at(size_t i) {
    // Return the data stored in the ith node
    // Utilize stdexcept to handle edge cases.
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========
    if (empty())
        throw length_error("empty list");
    if (i >= size())
        throw range_error("index exceeds list size");
    Node<T> *temp = head;
    for (size_t j = 0; j < i; j++)
        temp = temp->next;
    return temp->data;
    // ====================================================
}

template <typename T>
void SinglyLinkedList<T>::swap_head_tail() {
    // Swap the head and tail nodes in the linked list.
    // Utilize stdexcept to handle edge cases.
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========
    if (size() < 2)
        throw length_error("not enough items in list");
    Node<T> *new_tail = head;
    Node<T> *tail_successor = head;
    while (tail_successor->next != tail)
        tail_successor = tail_successor->next;

    // Case in which there are more than two nodes
    if (head->next != tail) {
        head = head->next;
        tail_successor->next = new_tail;
    }

    tail->next = head;
    new_tail->next = nullptr;
    head = tail;
    tail = new_tail;
    // ====================================================
}


template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
}

template <typename T>
bool SinglyLinkedList<T>::empty() {
    return head == nullptr;
}

template <typename T>
void SinglyLinkedList<T>::append(const T& newData) {
    Node<T> *newNode = new Node<T>(newData);   // create new node
    if (head == nullptr) {  // List empty
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void SinglyLinkedList<T>::prepend(const T& newData) {
    Node<T> *newNode = new Node<T>(newData);   // create new node
    if (head == nullptr) {  // list empty
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

template <typename T>
void SinglyLinkedList<T>::pop_front() {
    if (empty())
        throw length_error("empty list");
    Node<T> *temp = head;
    head = head->next;
    delete temp;
    if (head == nullptr)
        tail = nullptr;
}

template <typename T>
T& SinglyLinkedList<T>::front() {
    if(empty())
        throw std::length_error( "empty list" );
    return head->data;
}

template <typename T>
T& SinglyLinkedList<T>::back() {
    if(empty())
        throw std::length_error( "empty list" );
    return tail->data;
}

#endif

