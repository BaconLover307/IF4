/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 13-02-2020 */

#ifndef _ADDEXPRESSION_HPP_
#define _ADDEXPRESSION_HPP_
#include "Expression.hpp"

class AddExpression : public BinaryExpression {
protected:
	TerminalExpression* x;
	TerminalExpression* y;

public:
	AddExpression(TerminalExpression* x, TerminalExpression* y);
	AddExpression(AddExpression* a, TerminalExpression* y);
    virtual int solve();

};

#endif
