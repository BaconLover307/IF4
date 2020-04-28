// RekeningTabungan (turunan kelas Rekening)
// Kelas RekeningTabungan memiliki spesifikasi sebagai berikut.

//     Memiliki sukuBunga bulanan sebesar 0.05.
//     Konstruktor berparameter (String nama, double saldo).
//     Mengimplementasikan method setor(double) yang menambahkan saldo sebesar nilai parameter.
//     Mengimplementasikan method tarik(double) yang mengurangi saldo sebesar nilai parameter jika saldo cukup.
//     Mengimplementasikan method update() yang mengupdate nilai saldo setelah 1 bulan. Update dilakukan dengan cara
//			menambahkan saldo dengan bunga yang didapatkan dan menguranginya dengan biaya yang dikenakan.

// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 26-04-2020

class RekeningTabungan extends Rekening {
	public RekeningTabungan(String n, double s) {
		super(n, s, 0.05);
	}
	public void setor(double x) {
		this.saldo += x;

	}
	public void tarik(double x) {
		if (this.saldo >= x) {
			this.saldo -= x;
		}
	}
	public void update() {
        this.saldo += this.getSukuBunga()*this.getSaldo();
        this.saldo -= this.hitungBiaya();
	}
}