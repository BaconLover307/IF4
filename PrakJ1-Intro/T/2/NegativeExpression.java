// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 12-03-2020
// File 		: NegativeExpression.java

class NegativeExpression implements Expression {
	protected Expression x;

	public NegativeExpression(Expression x) {
		this.x = x;
	}

	public int solve() {
		return x.solve() * (-1);
	}
}
