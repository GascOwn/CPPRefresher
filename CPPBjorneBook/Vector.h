#include <initializer_list>

class Vector {
public:
	Vector(std::initializer_list<double>);
	Vector(int s);
	~Vector();

	double& operator[](int i);
	int size();
	void push_back(double);
	
private:
	double* elem;
	int sz;
};