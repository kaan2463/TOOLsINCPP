/*
 * list.h
 *
 *  Created on: May 18, 2020
 *      Author: khan
 */

#ifndef DATA_STRUCTURE_LIST_H_
#define DATA_STRUCTURE_LIST_H_

#define SIZE_STEP 10

template<class T>
class List {
private:
	T *array;
	int sz;
	int capacity;
public:
	List();
	void add(T item);
	T get(int index);
	int size();
	void sort();
	void sort(int (*comparator)(T, T));
	virtual ~List();
};

#endif /* DATA_STRUCTURE_LIST_H_ */
