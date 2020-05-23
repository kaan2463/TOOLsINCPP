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

bool is_number(const std::string &s) {
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		++it;
	return !s.empty() && it == s.end();
}

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
	int first_line = 0;
	int last_line = 2147483647; //max value
	for (int i = 1; i < argc; i++) {
		if (i == 1 && compare_character_array("--help", argv[i], false) == 0) {
			cout << "usage: " << argv[0]
					<< " ASC|DESC (optional) [options] < input > output" << endl
					<< "e.g. " << argv[0] << " DESC -f 12 -b 123" << endl;
			cout << "Options:" << endl;
			cout << "	-f :" << "first line to begin sort. " << "e.g.: -f 0"
					<< endl;
			cout << "	-l :" << "last line to begin sort. " << "e.g.: -l 23"
					<< endl;
			return 0;
		}
		if (i == 1) {
			if (compare_character_array("ASC", argv[i], false) == 0) {
				ascending = true;
			} else if (compare_character_array("DESC", argv[i], false) == 0) {
				ascending = false;
			}
		}
		if (compare_character_array("-f", argv[i], false) == 0) {
			i++;
			if (is_number(argv[i]) && i < argc) {
				first_line = atoi(argv[i]);
				continue;
			} else {
				cout
						<< "WARNING:	'-f' option has to be followed by a natural number!"
						<< endl;
				return 0;
			}

		} else if (compare_character_array("-l", argv[i], false) == 0) {
			i++;
			if (is_number(argv[i]) && i < argc) {
				last_line = atoi(argv[i]);
				continue;
			} else {
				cout
						<< "WARNING:	'-l' option has to be followed by a natural number!"
						<< endl;
				return 0;
			}
		}

		bool is_valid = compare_character_array("--help", argv[i], false) == 0
				|| compare_character_array("ASC", argv[i], false) == 0
				|| compare_character_array("DESC", argv[i], false) == 0
				|| compare_character_array("-f", argv[i], false) == 0
				|| compare_character_array("-l", argv[i], false) == 0;
		if (!is_valid) {
			cout << "Bad usage, for help: " << argv[0] << " --help" << endl;
			return 0;
		}
	}

	if (last_line < first_line) {
		cout << "WARNING:	first row number must be least than last line number!"
				<< endl;
		return 0;
	}

	List<char*> list;
	string str;
	int line_count = 1;

	while (getline(cin, str)) {
		if (line_count >= first_line && line_count <= last_line) {
			char *buffer = new char[str.length() + 1];
			strcpy(buffer, str.c_str());
			list.add(buffer);
		} else if (line_count == last_line + 1) {
			list.sort(
					ascending ?
							character_array_comparator_asc :
							character_array_comparator_desc);

			for (int i = 0; i < list.size(); i++) {
				cout << list.get(i) << endl;
			}
			cout << str << endl;
		} else {
			cout << str << endl;
		}
		line_count++;

	}

	return 0;
}

