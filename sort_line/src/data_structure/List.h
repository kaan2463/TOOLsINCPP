/*
 * list.h
 *
 *  Created on: May 18, 2020
 *      Author: khan
 */

#ifndef DATA_STRUCTURE_LIST_H_
#define DATA_STRUCTURE_LIST_H_

#define SIZE_STEP 10

class List {
private:
	int *array;
	int sz;
	int capacity;
public:
	List();
	void add(int item);
	int get(int index);
	int size();
	void sort();
	virtual ~List();
};

#endif /* DATA_STRUCTURE_LIST_H_ */
