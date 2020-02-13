/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 13-02-2020 */

#include "NegativeExpression.hpp"
#include <iostream>

using namespace std;

NegativeExpression::NegativeExpression(TerminalExpression* x) : UnaryExpression(x) {
    this->x = x;
}

void NegativeExpression::solve() {
	return this->x * -1;

}