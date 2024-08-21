#include "Student.h"
#include <iostream>
#include <list>
#include <string>
#include <numeric>

using namespace std;

Student_info::Student_info() : midterm(0), final(0), homework(list<double>{0}) {}
Student_info::Student_info(string n, double m, double f, list<double> hw) : name(n), midterm(m), final(f), homework(hw) {}
Student_info::Student_info(istream& is) { read(is); }

double Student_info::grade() const {
	if(!valid()) throw domain_error("Student has no homework");
	return 0.2 * midterm + 0.4 * final + 0.4 * average(homework);
}

istream& read_homework(istream&in, list<double>& v){
	if (in) {
		v.clear();
		double x;
		while (in >> x) v.push_back(x);
		in.clear();
	}
	return in;
}

istream&  Student_info::read(istream& is)
{
	is >> name >> midterm >> final;
	read_homework(is, homework);
	return is;
}

double average(const list<double>& v) {
	return v.empty() ? 0 : accumulate(v.begin(), v.end(), 0.0) / v.size();
}

bool compare(const Student_info& x, const Student_info& y) {
	return x.get_name() < y.get_name();
}

list<Student_info> extract_fails(list<Student_info>& students) {
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();
	while (iter != students.end()) {
		if (!iter->pass()) {
			fail.push_back(*iter);
			students.erase(iter); //erase returns an iterator positioned on the element after the erased element
		}
		else ++iter;
	}
	return fail;
}