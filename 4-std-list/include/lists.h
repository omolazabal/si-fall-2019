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

// For the following tasks manipulate main_list.

template <typename T>
void ListQuestions<T>::push_front_elements() {
    // Insert 3 elements at the front of the list
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========
    for (size_t i = 10; i < 13; i++)
        main_list.push_front(i);
    // ====================================================
}

template <typename T>
void ListQuestions<T>::delete_element() {
    // Delete the third element from the front of the list
    // Example:
    // BEFORE: [ 1  2  4  6  1  4  . . . ]
    //                 ^
    // AFTER:  [ 1  2  6  1  4  . . . ]
    typename list<T>::iterator it = main_list.begin();
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========
    for (size_t i = 1; i < 3; i++) it++;
    main_list.erase(it);
    // ====================================================
}

template <typename T>
typename list<T>::iterator ListQuestions<T>::get_element(const T &elem) {
    // Retreive an element from the list. Retrieve the element using an iterator.
    // Hint: utilize std::algorithm
    typename list<T>::iterator it = main_list.begin();
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========
    it = find(main_list.begin(), main_list.end(), elem);
    return it;


    // ====================================================
}

template <typename T>
void ListQuestions<T>::pop_front_elements() {
    // Remove 3 elements at the front of the list
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========
    for (size_t i = 1; i < 3; i++)
        main_list.pop_front();
    // ====================================================
}

template <typename T>
T ListQuestions<T>::sum() {
    // Find the sum of all of the elements of the list. Utilize iterators.
    typename list<T>::iterator it = main_list.begin();
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========
    T summation = *it;
    it++;
    while (it != main_list.end()) {
        summation += *it;
        it++;
    }
    return summation;
    // ====================================================
}

template <typename T>
void ListQuestions<T>::swap_elements() {
    // Swap the first and the last element in the list. Utilize iterators.
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========
    iter_swap(main_list.begin(), --main_list.end());
    // ====================================================
}

template <typename T>
void ListQuestions<T>::insert_elements(const T &elem) {
    // Insert an element at the 3rd position in the list.
    // Example:
    // BEFORE: [ 1  2  4  6  1  4  . . . ]
    //                 ^
    // AFTER:  [ 1  2  n  4  6  1  4  . . . ]
    typename list<T>::iterator it = main_list.begin();
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========
    for (size_t i = 1; i < 3; i++) it++;
    main_list.insert(it, elem);
    // ====================================================
}

template <typename T>
void ListQuestions<T>::sort() {
    // Sort the elements in the list in ascending order.
    // Hint: Use std::algorithm
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========
    main_list.sort();
    // ====================================================
}

template <typename T>
void ListQuestions<T>::clear_elements() {
    // Remove every element from the list.
    // ========= ONLY MODIFY BETWEEN THE LINES  ===========
    main_list.clear();
    // ====================================================
}


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

