#ifndef  GUARD_Student_info
#define GUARD_Student_info	

#include <list>
#include <string>

using namespace std;

class Student_info {

public:
	Student_info();
	Student_info(string, double, double, list<double>);
	Student_info(istream&);
	~Student_info() {}

	string get_name() const { return name; }
	bool valid() const { return !homework.empty(); }

	istream& read(istream&);
	double grade() const;
	bool pass() const { return grade() >= 60; }

private:
	string name;
	double midterm, final;
	list<double> homework
;
};

istream& read_homework(istream&, list<double>&);
double average(const list<double>&);
bool compare(const Student_info&, const Student_info&);

list<Student_info> extract_fails(list<Student_info>&);

#endif 
