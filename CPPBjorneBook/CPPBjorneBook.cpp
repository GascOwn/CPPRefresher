// CPPBjorneBook.cpp : Defines the entry point for the application.
//
#include "CPPBjorneBook.h"

using namespace std;
using std::sort;
using std::setprecision;

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

 
	return 0;
}
