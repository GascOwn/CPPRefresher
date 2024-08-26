// CPPBjorneBook.cpp : Defines the entry point for the application.
//
#include "CPPBjorneBook.h"

using namespace std;
using std::sort;
using std::setprecision;

vector<string> split(const string& s) {
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		while (i != s.size() && isspace(s[i])) ++i; //ignore leading blanks in first iteration

		string_size j = i;
		while (j != s.size() && !isspace(s[j])) j++; //find end of word

		if (i != j) {
			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return ret;
}

void read_and_split() {
	string s;
	while (getline(cin, s)) {
		vector<string> v = split(s);
		for (vector<string>::size_type i = 0; i != v.size(); ++i) {
			cout << v[i] << endl;
		}
	}
}

template<class T> 
	T median(vector<T> v) {
	typedef typename vector<T>::size_type vec_sz;
	vec_sz size = v.size();
	if (size == 0) {
		throw domain_error("median of an empty vector");
	}
	sort(v.begin(), v.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

template<class In, class X> 
In my_find (In begin, In end, const X& x) {
	while (begin != end && *begin != x) {
		++begin;
	}
	return begin;
}

int main()
{
	string x;
	vector <string> bottom = split("The quick brown fox jumps over the lazy dog");

	vector<string> ret;

	auto sum_two = [](int a, int b) -> int {return a + b; }; // lambda notation good for closures / callbacks

	cout << sum_two(2, 3) << endl;

	copy(bottom.begin(), bottom.end(), back_inserter(ret));

	for (vector<string>::const_iterator it = ret.begin(); it != ret.end(); ++it) {
		cout << *it << endl;
	}

	list<int> l { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	list<int>::iterator cosa = my_find(l.begin(), l.end(), 5);

	cout << *cosa << endl;


	/*map
	<string, int> counters;

	while(cin >> x) {
		++counters[x]; //increment the counter for the word x
	}

	for(map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it) {
		cout << it->first << "\t" << it->second << endl;
	}*/
 
	return 0;
}
