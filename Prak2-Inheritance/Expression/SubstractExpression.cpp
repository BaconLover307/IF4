/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 13-02-2020 */

#include "SubstractExpression.hpp"
#include <iostream>

using namespace std;

SubstractExpression::SubstractExpression(Expression* x, Expression* y) : BinaryExpression(x,y) {
}

int SubstractExpression::solve() {
	return x->solve() - y->solve();
    
}