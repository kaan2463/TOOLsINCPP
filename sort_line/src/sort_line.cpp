//============================================================================
// Name        : sort_line.cpp
// Author      : Khan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <string.h>
#include "data_structure/List.cpp"
using namespace std;

int compare_character_array(const char *s1, const char *s2, bool ascending) {
	for (;; s1++, s2++) {
		int d = tolower((unsigned char) *s1) - tolower((unsigned char) *s2);
		if (d != 0 || !*s1)
			return ascending ? (-1) * d : d;
	}
	throw "UnsatisfiedReturn";
}

int character_array_comparator_asc(char *first_arg, char *second_arg) {
	return compare_character_array(first_arg, second_arg, true);
}

int character_array_comparator_desc(char *first_arg, char *second_arg) {
	return compare_character_array(first_arg, second_arg, false);
}

int main(int argc, char *argv[]) {
	bool ascending = true;
	for (int i = 0; i < argc; i++) {
		if (i == 1 && compare_character_array("--help", argv[i], false) == 0) {
			cout << "usage: " << argv[0]
					<< " [ASC|DESC (optional)] < input > output" << endl;
			return 0;
		}
		if (i == 1) {
			if (compare_character_array("ASC", argv[i], false) == 0) {
				ascending = true;
			} else if (compare_character_array("DESC", argv[i], false) == 0) {
				ascending = false;
			} else {
				cout << "Bad usage, for help: " << argv[0] << " --help" << endl;
				return 0;
			}
			break;
		}
	}

	List<char*> list;
	string str;
	while (getline(cin, str)) {
		char *buffer = new char[str.length() + 1];
		strcpy(buffer, str.c_str());
		list.add(buffer);
	}

	list.sort(
			ascending ?
					character_array_comparator_asc :
					character_array_comparator_desc);

	for (int i = 0; i < list.size(); i++) {
		cout << list.get(i) << endl;
	}

	return 0;
}
