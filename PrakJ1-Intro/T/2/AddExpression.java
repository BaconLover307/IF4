// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 12-03-2020
// File 		: AddExpression.java

class AddExpression implements Expression {
	protected Expression x;
	protected Expression y;

	public AddExpression(Expression x, Expression y) {
		this.x = x;
		this.y = y;
	}

	public int solve() {
		return x.solve() + y.solve();
	}
}