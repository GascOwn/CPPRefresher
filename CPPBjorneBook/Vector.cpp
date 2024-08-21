#include "Vector.h"
#include <initializer_list>
#include <iostream>

using namespace std;

Vector::Vector(std::initializer_list<double> lst) : elem{ new double[lst.size()] }, sz{ static_cast<int>(lst.size()) } {
	copy(lst.begin(), lst.end(), elem);
}

Vector::Vector(int s) {
	elem = new double[s];
	sz = s;

	for(int i = 0; i < s; ++i) elem[i] = 0;
}

Vector::~Vector() { delete[] elem; }

double& Vector::operator[](int i) {
	if (i < 0 || size() <= i) throw out_of_range{ "Vector::operator[]" };
	return elem[i];
}

int Vector::size() {
	return sz;
}

void Vector::push_back(double d) {
	double* new_elem = new double[sz + 1];
	for (int i = 0; i < sz; ++i) new_elem[i] = elem[i];
	new_elem[sz] = d;
	delete[] elem;
	elem = new_elem;
	++sz;
}