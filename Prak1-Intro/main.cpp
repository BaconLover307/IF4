#include "A.hpp"
#include <iostream>

using namespace std;

int main() {

	A * a = new A('1');
	A * b = new A('2');
	A * c = new A(*a);
	c = b;
	b -> show();
	delete c;
	delete b;
	delete a;
	
}
