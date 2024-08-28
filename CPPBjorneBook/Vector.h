#include <memory>

using namespace std;

// When creating a class, it is essential to determine how creation, copy, assignment, and destruction of objects are handled.
template<class T> class Vec {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;

	Vec<T>() { create(); }
	explicit Vec<T>(size_t n, const T& val = T()) { create(n, val); }

	~Vec<T>() { uncreate(); }

	Vec<T>(const Vec<T>& v) { create(v.begin(), v.end()); }

	// number of elements, calculated by subtracting the address of the first element from the address of the last element
	size_type size() const { return avail - data; }
	T& operator[](size_type i) { return data[i]; }
	const T& operator[](size_type i) const { return data[i]; }

	Vec& operator=(const Vec&);

	void push_back(const T& val) {
		if (avail == limit) {
			grow();
		}
		unchecked_append(val);
	}

	iterator begin() { return data; }
	const_iterator begin() const { return data; }

	iterator end() { return limit; }
	const_iterator end() const { return limit; }

private:
	// data <= avail <= limit is the class invariant
	iterator data; // first element in the Vec
	iterator avail; // one past the last element
	iterator limit; // one past the last allocated element

	allocator<T> alloc;

	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	void uncreate();
	void grow();
	void unchecked_append(const T&);
};