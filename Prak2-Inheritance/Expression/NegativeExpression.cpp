/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 13-02-2020 */

#include "NegativeExpression.hpp"
#include <iostream>

using namespace std;

NegativeExpression::NegativeExpression(Expression* x) : UnaryExpression(x) {
    //
}

int NegativeExpression::solve() {
	return x->solve() * -1;

}