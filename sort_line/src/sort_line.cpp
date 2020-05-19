//============================================================================
// Name        : sort_line.cpp
// Author      : Khan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "data_structure/List.h"
using namespace std;

int main() {
	List list;
	list.add(2);
	list.add(4);
	list.add(6);
	list.add(7);
	list.add(1);
	list.add(-145);
	list.add(5);
	list.add(12);
	list.add(-13);
	list.add(-12);
	list.add(123);
	list.add(8);
	list.add(3);
	list.add(0);
	list.add(1);
	list.add(2);
	list.add(9);

	list.sort();

	for (int i = 0; i < list.size(); i++) {
		cout << i << " " << list.get(i) << endl;
	}

	return 0;
}
