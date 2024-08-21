// CPPBjorneBook.cpp : Defines the entry point for the application.
//
#include "CPPBjorneBook.h"

using namespace std;
using std::sort;
using std::setprecision;

int main()
{


	//lists are implemented as doubly linked lists, so they are not contiguous in memory and do not support random access (i.e. no [] operator)
	list<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	cout << "Insert student data: " << endl;
	while (record.read(cin)) {
		maxlen = max(maxlen, record.get_name().size());
		students.push_back(record);
	}

	students.sort(compare);

	//using iterators instead of indices, using pointer notation
	for (list<Student_info>::const_iterator iter = students.begin(); iter != students.end(); ++iter) {

		cout << iter->get_name() << string(maxlen + 1 - iter->get_name().size(), ' ');
		double grade = iter->grade();
		streamsize prec = cout.precision();
		cout << setprecision(3) << grade << setprecision(prec) << endl;
	}

	return 0;
}
