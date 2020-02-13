/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 13-02-2020 */

#include "AddExpression.hpp"
#include <iostream>

using namespace std;

AddExpression::AddExpression(TerminalExpression* x, TerminalExpression* y) : BinaryExpression(x), BinaryExpression(y) {
    this->x = x;
    this->y = y;
}

void AddExpression::solve() {
    return this->x + this->y;
}