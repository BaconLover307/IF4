/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 13-02-2020 */

#ifndef _NEGATIVEEXPRESSION_HPP_
#define _NEGATIVEEXPRESSION_HPP_
#include "Expression.hpp"

class NegativeExpression : public UnaryExpression {
protected:
	TerminalExpression* x;

public:
	NegativeExpression(TerminalExpression* x);
    virtual int solve();

};

#endif