#include "Bank.hpp"
#include <iostream>

int main() {
	Account me("100", 100);
	Account you;
	Bank bca;
	me.setNumber("100");
	you.setNumber("200");
	Account mor= bca.getAccount(1);



	return 0;
}