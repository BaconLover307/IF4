/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 13-02-2020 */

#ifndef _SUBSTRACTEXPRESSION_HPP_
#define _SUBSTRACTEXPRESSION_HPP_
#include "Expression.hpp"

class SubstractExpression : public BinaryExpression {
protected:
	TerminalExpression* x;
	TerminalExpression* y;

public:
	SubstractExpression(TerminalExpression* x, TerminalExpression* y);
    virtual int solve();

};

#endif