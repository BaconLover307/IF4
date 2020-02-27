/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 13-02-2020 */

#include "AddExpression.hpp"
#include <iostream>

using namespace std;

AddExpression::AddExpression(Expression* x, Expression* y) : BinaryExpression(x,y) {
}

int AddExpression::solve() {
    return x->solve() + y->solve();
}
