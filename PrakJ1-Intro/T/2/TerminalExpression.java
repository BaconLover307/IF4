// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 12-03-2020
// File 		: TerminalExpression.java

class TerminalExpression implements Expression {
	protected int x;

	public TerminalExpression(int x) {
		this.x = x;
	}

	public int solve() {
		return x;
	}
}
