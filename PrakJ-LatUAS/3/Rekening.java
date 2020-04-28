// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 28-04-2020
// Topic 		: Interface

abstract class Rekening {
    protected String nama;
    protected double saldo;
    protected double sukuBunga;

    public Rekening(String nama, double saldo, double sukuBunga) {
        this.nama = nama;
        if (saldo < 0) this.saldo = 0;
        else this.saldo = saldo;
        this.sukuBunga = sukuBunga;
    }

    abstract public void setor(double x);
    abstract public void tarik(double x);
    abstract public void update();

    public double hitungBiaya() {
        return Math.min(10.0, 0.1*this.saldo);
    }

    public String getNama() {return this.nama;}
    public double getSaldo() {return this.saldo;}
    public double getSukuBunga() {return this.sukuBunga;}
}