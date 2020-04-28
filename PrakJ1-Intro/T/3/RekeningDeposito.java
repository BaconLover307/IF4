// RekeningDeposito (turunan kelas Rekening)
// Kelas RekeningDeposito memiliki spesifikasi sebagai berikut.

//     Atribut bertipe integer bernama bulan yang menandakan lamanya rekening telah dibuat.
//     Memiliki sukuBunga tahunan sebesar 0.15.
//     Konstruktor berparameter (String nama, double saldo).
//     Mengimplementasikan method setor(double) yang mencetak "Tidak dapat melakukan penyetoran uang untuk rekening ini." diakhiri newline.
//     Mengimplementasikan method tarik(double) yang mencetak "Tidak dapat melakukan penarikan uang sebagian untuk rekening ini." diakhiri newline.
//     Mengimplementasikan method update() yang mengupdate nilai saldo setelah 1 bulan. Update dilakukan dengan cara menambahkan saldo
//     	dengan bunga yang didapatkan (jika 1 tahun berlalu) dan menguranginya dengan biaya yang dikenakan.
//     Method tarik() yang menarik semua saldo yang terdapat pada rekening. Jika penarikan dilakukan sebelum 1 tahun akan terdapat penalti
//     	sebesar 20% dari saldo yang ditandai dengan mencetak "Anda terkena penalti sebesar <penalti>." diakhiri newline.

// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 12-03-2020

class RekeningDeposito extends Rekening {
	protected int bulan;
	public RekeningDeposito(String nama, double saldo) {
		super(nama,saldo,0.15);
	}
	public void setor(double x) {
		System.out.println("Tidak dapat melakukan penyetoran uang untuk rekening ini\n");
	}
	public void tarik(double x) {
		System.out.println("Tidak dapat melakukan penarikan uang sebagian untuk rekening ini\n");

	}
	public void update() {
		if (this.bulan % 12 == 0) {
			this.saldo += this.getSukuBunga() * this.getSaldo();
        }
        this.saldo -= this.hitungBiaya();
	}

	public void tarik() {
		if (this.bulan < 12) {
			double pen = 0.2 * this.getSaldo();
			System.out.println("Anda terkena penalti sebesar " + pen + ".");
		}
		this.saldo = 0;
	}
}