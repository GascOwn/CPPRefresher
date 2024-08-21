#include "Vector.h"
#include <initializer_list>
#include <list>



class Container {
public:
	virtual double& operator[](int) = 0;
	virtual int size() = 0;
	virtual ~Container() {}
};

void use(Container&);

class Vector_container : public Container {
	Vector v;
public:
	Vector_container(int);
	~Vector_container();

	double& operator[](int);
	int size();
};

class List_container : public Container {
	std::list<double> ld;
public:
	List_container();
	List_container(std::initializer_list<double>);
	~List_container();

	double& operator[](int);
	int size();

};