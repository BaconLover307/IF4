// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 28-04-2020
// Topic 		: Interface

// Di bawah ini, kelas TerminalExpression menginherit Expression
// Namun, sekarang Expression merupakan interface, bukan kelas.
class TerminalExpression implements Expression {

    protected int x;

    public TerminalExpression(int x) {
    this.x = x;
  }

  public int solve() {
    return this.x;
  }
}