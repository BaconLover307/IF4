// RekeningGiro (turunan kelas Rekening)
// Kelas RekeningGiro memiliki spesifikasi sebagai berikut.

//     Memiliki atribut bertipe boolean bernama penalti yang menandakan apakah rekening dikenakan penalti atau tidak.
//     	Penalti dikenakan sebesar 10 pada akhir bulan jika pada bulan tersebut saldo pernah kurang dari 500.
//     Memiliki sukuBunga bulanan sebesar 0.07.
//     Setiap transaksi yang dilakukan (setor dan tarik) dikenakan biaya sebesar 0.1.
//     Memiliki konstruktor berparameter (String nama, double saldo).
//     Mengimplementasikan method setor(double) yang menambahkan saldo sebesar nilai parameter dan menguranginya sebesar biaya transaksi.
//     	Uang yang disetor pasti lebih besar dari biaya transaksi.
//     Mengimplementasikan method tarik(double) yang mengurangi saldo sebesar nilai parameter dan biaya transaksi jika saldo cukup.
//     Mengimplementasikan method update() yang mengupdate nilai saldo setelah 1 bulan. Update dilakukan dengan cara menambahkan saldo dengan
//     	bunga yang didapatkan dan menguranginya dengan biaya yang dikenakan dan penalti (jika ada). Jika saldo menjadi negatif,
//     	set saldo menjadi 0.

// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 12-03-2020

class RekeningGiro extends Rekening {
	private boolean penalti;


	public RekeningGiro(String n, double s) {
		super(n,s,0.07);
		penalti = false;
	}
	public void setor(double x) {
		saldo += x;
		saldo -= 0.1*x;

	}
	public void tarik(double x) {
		if (saldo>=1.1*x) saldo -= 1.1*x; 

	}
	public void update() {

	}
}