/*
 * MergeSort.h
 *
 *  Created on: May 18, 2020
 *      Author: khan
 */

#ifndef DATA_STRUCTURE_MERGESORT_H_
#define DATA_STRUCTURE_MERGESORT_H_

class MergeSort {
private:
	template<class T>
	static T* merge(T*, T*, int, int);
public:
	MergeSort();
	template<class T>
	static T* sort(T*, int);
	static int* sortInt(int*, int);
	virtual ~MergeSort();
};

#endif /* DATA_STRUCTURE_MERGESORT_H_ */
