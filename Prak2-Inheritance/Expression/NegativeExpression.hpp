/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 13-02-2020 */

#ifndef _NEGATIVEEXPRESSION_HPP_
#define _NEGATIVEEXPRESSION_HPP_
#include "Expression.hpp"

class NegativeExpression : public UnaryExpression {
public:
	NegativeExpression(Expression* x);
    virtual int solve();

};

#endif