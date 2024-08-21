#include "Container.h"
#include <iostream>

void use(Container& c) {
	const int sz = c.size();
	for (int i = 0; i != sz; ++i)
		std::cout << c[i] << '\n';
}


Vector_container::Vector_container(int s) : v(s) {}
Vector_container:: ~Vector_container() {}

double& Vector_container::operator[](int i) { return v[i]; }
int Vector_container::size() { return v.size(); }

List_container::List_container() {};
List_container::List_container(std::initializer_list<double> lst) : ld(lst) {}
List_container::~List_container() {}

double& List_container::operator[](int i) {
	for (auto& x : ld) {
		if (i == 0) return x;
		--i;
	}
	throw std::out_of_range{ "List_container::operator[]" };
}

int List_container::size() { return ld.size(); }