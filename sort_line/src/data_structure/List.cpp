/*
 * list.cpp
 *
 *  Created on: May 18, 2020
 *      Author: khan
 */

#include <algorithm>
#include <iterator>
#include "List.h"
#include "MergeSort.h"

List::List() {
	array = new int[SIZE_STEP];
	capacity = SIZE_STEP;
	sz = 0;
}

List::~List() {
	delete array;
}

int List::get(int index) {
	if (index < sz) {
		return array[index];
	}
	throw "IndexNotInBoundException";
}

void List::add(int item) {
	if (sz < capacity) {
		array[sz] = item;
		sz++;
		return;
	}

	int *temp = new int[capacity + SIZE_STEP];
	std::copy(array, array + capacity, temp);
	delete[] array;
	array = temp;
	capacity += SIZE_STEP;
	add(item);
}

int List::size() {
	return sz;
}
void List::sort() {
	int *temp = MergeSort::sortInt(array, sz);
	delete[] array;
	array = temp;
}

