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
// Tanggal      : 12-03-2020

abstract class Rekening {
   	private String nama;
    private double saldo;
    private double sukuBunga;

    public Rekening(String n, double s, double sB) {
    	nama = n;
    	sukuBunga = sB;
    	saldo = s;
    	if (saldo < 0) saldo = 0;
    }

    public String getNama() {
    	return nama;
    }
    public double getSaldo() {
    	return saldo;
    }
    public double getSukuBunga() {
    	return sukuBunga;
    }

    abstract public void setor(double x);
    abstract public void tarik(double x);
    abstract public void update();

    public void hitungBiaya(){

    }
}