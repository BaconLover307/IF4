// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 28-04-2020
// Topic 		: Interface

class RekeningTabungan extends Rekening {

    public RekeningTabungan(String nama, double saldo) {
        super(nama, saldo, 0.05);
    }

    public void setor(double x) {
        this.saldo += x;
    }

    public void tarik(double x) {
        if (x <= this.saldo) {
            this.saldo -= x;
        }
    }
    public void update() {
        this.saldo += this.getSukuBunga()*this.saldo - this.hitungBiaya();
    }

}