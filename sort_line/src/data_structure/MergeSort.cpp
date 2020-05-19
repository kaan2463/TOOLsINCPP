/*
 * MergeSort.cpp
 *
 *  Created on: May 18, 2020
 *      Author: khan
 */

#include "MergeSort.h"

#include <iostream>

MergeSort::MergeSort() {
}
//FIXME: now, just for the integers
template<typename T>
T* MergeSort::merge(T *arr1, T *arr2, int sz1, int sz2) {
	int *temp = new int[sz1 + sz2];

	//indexes
	int ind_1 = 0, ind_2 = 0;

	for (int i = 0; i < sz1 + sz2; i++) {

		//FIXME: For now it is just sorting by ascending

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

		if (arr1[ind_1] < arr2[ind_2]) {
			temp[i] = arr1[ind_1];
			ind_1++;
		} else {
			temp[i] = arr2[ind_2];
			ind_2++;
		}
	}

	return temp;
}

MergeSort::~MergeSort() {
}

template<typename T>
T* MergeSort::sort(T *array, int sz) {

	if (sz == 1) {
		return array;
	}

	if (sz < 1) {
		return new T[0];
	}

	int *arr1, *arr2, sz1 = 0, sz2 = 0;
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

	return merge(sort(arr1, sz1), sort(arr2, sz2), sz1, sz2);
}

int* MergeSort::sortInt(int *array, int int1) {
	return MergeSort::sort(array, int1);
}
