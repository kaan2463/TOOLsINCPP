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
	static T* merge(T*, T*, int, int, int (*comparator)(T, T));
public:
	template<class T>
	static T* sort(T*, int, int (*comparator)(T, T));
};

#endif /* DATA_STRUCTURE_MERGESORT_H_ */
