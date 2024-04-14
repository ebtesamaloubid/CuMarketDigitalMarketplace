#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstdlib>
#include "defs.h"
using namespace std;

template<typename T>
class List {
public:
    List();
    ~List();
    List& operator+=(const T& s);
    List& operator-=(const T& s);
    T& operator[](int index);
    const T& operator[](int index) const;
    int getSize() const;
    bool isFull() const;
    void clear();

private:
    int numElements;
    T* elements;
};

template<typename T>
List<T>::List() {
    elements = new T[MAX_ARRAY];
    numElements = 0;
}

template<typename T>
List<T>::~List() {
    delete[] elements;
}

template<typename T>
List<T>& List<T>::operator+=(const T& s) {
    if (numElements >= MAX_ARRAY)   return *this;
  	elements[numElements++] = s;
	return *this;
}

template<typename T>
List<T>& List<T>::operator-=(const T& s) {
    int index = 0;
    while (index < numElements) {
        if (elements[index] == s) {
            for (int j = index; j < numElements - 1; ++j) {
                elements[j] = elements[j + 1];
            }
            --numElements;
            break;
        }
        ++index;
    }
    return *this;
}

template<typename T>
T& List<T>::operator[](int i) {
    if (i < 0 || i >= numElements) {
        cerr << " index out of bounds" << endl;
        exit(1);
    }
    return elements[i];
}

template<typename T>
const T& List<T>::operator[](int i) const {
    if (i < 0 || i >= numElements) {
        cerr << "index out of bounds" << endl;
        exit(1);
    }
    return elements[i];
}

template<typename T>
int List<T>::getSize() const {
    return numElements;
}

template<typename T>
bool List<T>::isFull() const {
    return numElements >= MAX_ARRAY;
}

template<typename T>
void List<T>::clear() {
    numElements = 0;
}

#endif 
