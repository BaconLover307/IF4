// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 28-04-2020
// Topic 		: Interface

// Di bawah ini, kelas NegativeExpression menginherit Expression
// Namun, sekarang Expression merupakan interface, bukan kelas.
public class NegativeExpression implements Expression {
    // Di Java, tidak ada konsep pointer. Polymorphism dapat dilakukan
    // pada reference, bukan pointer.
    protected Expression x;

    public NegativeExpression(Expression x) {
        this.x = x;
    }

    public int solve() {
        return -1 * this.x.solve();
    }
}