/*
 * list.cpp
 *
 *  Created on: May 18, 2020
 *      Author: khan
 */

#include <algorithm>
#include <iterator>
#include "List.h"
//FIXME: error when include '.h'
#include "MergeSort.cpp"

template<class T>
List<T>::List() {
	array = new T[SIZE_STEP];
	capacity = SIZE_STEP;
	sz = 0;
}

template<class T>
List<T>::~List() {
	delete array;
}

template<class T>
T List<T>::get(int index) {
	if (index < sz) {
		return array[index];
	}
	throw "IndexNotInBoundException";
}

template<class T>
void List<T>::add(T item) {
	if (sz < capacity) {
		array[sz] = item;
		sz++;
		return;
	}

	T *temp = new T[capacity + SIZE_STEP];
	std::copy(array, array + capacity, temp);
	delete[] array;
	array = temp;
	capacity += SIZE_STEP;
	add(item);
}

template<class T>
int List<T>::size() {
	return sz;
}

template<class T>
void List<T>::sort() {
	T *temp = MergeSort::sort<T>(array, sz, &default_comparator);
	delete[] array;
	array = temp;
}

template<class T>
void List<T>::sort(int (*comparator)(T, T)) {
	T *temp = MergeSort::sort<T>(array, sz, comparator);
	delete[] array;
	array = temp;
}

