/*
 * MergeSort.cpp
 *
 *  Created on: May 18, 2020
 *      Author: khan
 */

#include "MergeSort.h"

#include <iostream>
//FIXME: better approach to avoid memory problem
template<typename T>
T* MergeSort::merge(T *arr1, T *arr2, int sz1, int sz2,
		int (*comparator)(T, T)) {
	T *temp = new T[sz1 + sz2];

	//indexes
	int ind_1 = 0, ind_2 = 0;

	for (int i = 0; i < sz1 + sz2; i++) {

		if (ind_1 >= sz1) {
			temp[i] = arr2[ind_2];
			ind_2++;
			continue;
		}
		if (ind_2 >= sz2) {
			temp[i] = arr1[ind_1];
			ind_1++;
			continue;
		}

		T first_arg = arr1[ind_1];
		T second_arg = arr2[ind_2];

		if (comparator(first_arg, second_arg) > 0) {
			temp[i] = arr1[ind_1];
			ind_1++;
		} else {
			temp[i] = arr2[ind_2];
			ind_2++;
		}
	}

	return temp;
}

template<typename T>
int default_comparator(T first_arg, T second_arg) {
	if (first_arg < second_arg) {
		return -1;
	} else if (first_arg == second_arg) {
		return 0;
	} else {
		return 1;
	}
}

template<typename T>
T* MergeSort::sort(T *array, int sz, int (*comparator)(T, T)) {

	if (sz == 1) {
		return array;
	}

	if (sz < 1) {
		return new T[0];
	}

	T *arr1, *arr2;
	int sz1 = 0, sz2 = 0;
	sz1 = sz / 2;
	sz2 = sz - sz1;
	arr1 = new T[sz1];
	arr2 = new T[sz2];

	for (int i = 0; i < sz1; i++) {
		arr1[i] = array[i];
	}
	for (int i = 0; i < sz2; i++) {
		arr2[i] = array[i + sz1];
	}

	//FIXME:repetetive comparator
	return merge(sort(arr1, sz1, comparator), sort(arr2, sz2, comparator), sz1,
			sz2, comparator);
}

