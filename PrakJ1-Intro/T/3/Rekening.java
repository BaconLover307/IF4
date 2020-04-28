// Abstract Class Rekening
// Kelas Rekening memiliki spesifikasi sebagai berikut.

//     Atribut bertipe String bernama nama yang menyimpan nama pemilik rekening tersebut.
//     Atribut bertipe double bernama saldo yang menyimpan saldo yang terdapat pada rekening tersebut.
//     Atribut bertipe double bernama sukuBunga yang menyimpan sukuBunga untuk rekening tersebut.
//     Konstruktor berparameter (String nama, double saldo, double sukuBunga). Jika saldo bernilai negatif, set menjadi 0.
//     Method abstract setor(double), tarik(double), dan update() dengan akses public.
//     Method hitungBiaya() yang menghitung biaya yang dikenakan pada akhir setiap bulan. Biaya yang dikenakan sebesar minimal dari 10 dan 10% saldo.
//     Getter untuk ketiga atribut (format penamaan: getNamaAtribut).

// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 26-04-2020

abstract class Rekening {
   	protected String nama;
    protected double saldo;
    protected double sukuBunga;

    public Rekening(String nama, double saldo, double sukuBunga) {
    	this.nama = nama;
    	this.sukuBunga = sukuBunga;
    	if (saldo < 0) this.saldo = 0;
        else this.saldo = saldo;
    }

    public String getNama() {
    	return this.nama;
    }
    public double getSaldo() {
    	return this.saldo;
    }
    public double getSukuBunga() {
    	return this.sukuBunga;
    }

    abstract public void setor(double x);
    abstract public void tarik(double x);
    abstract public void update();

    public double hitungBiaya(){
        return Math.min(0.1 * this.saldo, 10.0);
    }
}