//============================================================================
// Name        : sort_line.cpp
// Author      : Khan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include "data_structure/List.cpp"
using namespace std;

int compare_character_array(const char *s1, const char *s2) {
	for (;; s1++, s2++) {
		int d = tolower((unsigned char) *s1) - tolower((unsigned char) *s2);
		if (d != 0 || !*s1)
			return d;
	}
	throw "UnsatisfiedReturn";
}

int character_array_comparator(char *first_arg, char *second_arg) {
	return compare_character_array(first_arg, second_arg);
}

int main() {
	List<char*> list;
	list.add("123");
	list.add("ww");
	list.add("w");
	list.add("s");
	list.add("ADFq");
	list.add("a");
	list.add("A");
	list.add("asd");
	list.add("asdafds");
	list.add("adsadf");
	list.add("asdassa");
	list.add("asdasd");
	list.add("adf");
	list.add("erhgkjkljkjkkkjk");
	list.add("jghjgh");
	list.add("ee");
	list.add("dsf");

	list.sort(character_array_comparator);

	for (int i = 0; i < list.size(); i++) {
		cout << "obj" << i << " " << list.get(i) << endl;
	}

	cout << compare_character_array("1", "2") << endl;
	cout << compare_character_array("asc", "f") << endl;
	cout << compare_character_array("fsd", "as") << endl;
	cout << compare_character_array("2", "1") << endl;
	cout << compare_character_array("2521", "2") << endl;

	return 0;
}
