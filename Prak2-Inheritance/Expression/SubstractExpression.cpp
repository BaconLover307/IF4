/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 13-02-2020 */

#include "SubtractExpression.hpp"
#include <iostream>

using namespace std;

int funcPtrTerminal(TerminalExpression *X) {
	return X->x;
}

SubstractExpression::SubstractExpression(TerminalExpression* x, TerminalExpression* y) : BinaryExpression(x), BinaryExpression(y) {
    this->x = x;
    this->y = y;
}

void SubstractExpression::solve() {
	return funcPtrTerm(this->x) - funcPtrTerm(this->y);
    
}