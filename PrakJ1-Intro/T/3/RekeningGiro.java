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
// Tanggal      : 26-04-2020

class RekeningGiro extends Rekening {
	private boolean penalti;


	public RekeningGiro(String nama, double saldo) {
		super(nama,saldo,0.07);
		this.penalti = false;
		if (this.saldo < 500) {
			this.penalti = true;
		} 
	}
	public void setor(double x) {
		this.saldo += x - 0.1;
		if (this.saldo < 500) {
			this.penalti = true;
		}

	}
	public void tarik(double x) {
		if (this.saldo >= x+0.1) {
			this.saldo -= x - 0.1;
		}
		if (this.saldo < 500) {
			this.penalti = true;
		}

	}
	public void update() {
        this.saldo += this.getSukuBunga() * this.saldo;
        this.saldo -= this.hitungBiaya();
		if (this.penalti) {
			this.saldo -= 10;
		}
		if (this.saldo > 500) {
			this.penalti = false;
		}
		if (this.saldo < 0) {
			this.saldo = 0;
		}
	}
}