#ifndef LISTS
#define LISTS

#include <list>
#include <algorithm>
using namespace std;

template <typename T> 
class ListQuestions {
private:
   list<T> main_list;
public:
   ListQuestions(list<T>);
   list<T>& get_list();

   void push_front_elements();
   void pop_front_elements();
   void delete_element();
   typename list<T>::iterator get_element(const T &);
   T sum();
   void swap_elements();
   void insert_elements(const T &);
   void sort();
   void clear_elements();
};

// ===== TODO ===== //
// For the following tasks manipulate main_list.

// Insert 3 elements at the front of the list
template <typename T>
void ListQuestions<T>::push_front_elements() {
    for (size_t i = 10; i < 13; i++)
        main_list.push_front(i);
}

// Delete the third element from the front of the list
// Example:
// BEFORE: [ 1  2  4  6  1  4  . . . ]
//                 ^
// AFTER:  [ 1  2  6  1  4  . . . ]
template <typename T>
void ListQuestions<T>::delete_element() {
    typename list<T>::iterator it = main_list.begin();
    for (size_t i = 1; i < 3; i++) it++;
    main_list.erase(it);
}

// Retreive an element from the list. Retrieve the element using an iterator.
// Hint: utilize std::algorithm
template <typename T>
typename list<T>::iterator ListQuestions<T>::get_element(const T &elem) {
    typename list<T>::iterator it = main_list.begin();
    it = find(main_list.begin(), main_list.end(), elem);
    return it;
}

// Remove 3 elements at the front of the list
template <typename T>
void ListQuestions<T>::pop_front_elements() {
    for (size_t i = 1; i < 3; i++)
        main_list.pop_front();
}

// Find the sum of all of the elements of the list. Utilize iterators.
template <typename T>
T ListQuestions<T>::sum() {
    typename list<T>::iterator it = main_list.begin();
    T summation = *it;
    it++;
    while (it != main_list.end()) {
        summation += *it;
        it++;
    }
    return summation;
}

// Swap the first and the last element in the list. Utilize iterators.
template <typename T>
void ListQuestions<T>::swap_elements() {
    iter_swap(main_list.begin(), --main_list.end());
}

// Insert an element at the 3rd position in the list.
// Example:
// BEFORE: [ 1  2  4  6  1  4  . . . ]
//                 ^
// AFTER:  [ 1  2  n  4  6  1  4  . . . ]
template <typename T>
void ListQuestions<T>::insert_elements(const T &elem) {
    typename list<T>::iterator it = main_list.begin();
    for (size_t i = 1; i < 3; i++) it++;
    main_list.insert(it, elem);
}

// Sort the elements in the list in ascending order.
// Hint: Use std::algorithm
template <typename T>
void ListQuestions<T>::sort() {
    main_list.sort();
}

// Remove every element from the list.
template <typename T>
void ListQuestions<T>::clear_elements() {
    main_list.clear();
}

// ===== END TODO ===== //

template <typename T>
ListQuestions<T>::ListQuestions(list<T> copy_list) {
    for (T i : copy_list)
        main_list.push_back(i);
}

template <typename T>
list<T>& ListQuestions<T>::get_list() {
    return main_list;
}

#endif

