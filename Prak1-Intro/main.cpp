#include "A.hpp"
#include <iostream>

using namespace std;

int main() {

	A x('1');
	A y('2');
	A z(x);
	z = y;
	y.show();

	return 0;
	/*
	A * a = new A('1');
	A * b = new A('2');
	A * c = new A(*a);
	c = b;
	b -> show();
	delete c;
	delete b;
	delete a;
	*/
}
