// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 19-03-2020
// File 		: Employee.java

// Buatlah sebuah kelas Employee dengan spesifikasi sebagai berikut:

//     Memiliki atribut bernama hasMarried bertipe boolean yang memiliki nilai default false
//     Memiliki sebuah default constructor.
//     Memiliki method public void setHasMarried(boolean hasMarried) yang mengubah
//          atribut hasMarried sesuai parameter.
//     Memiliki method public int calculateSalary(int workHour) untuk menghitung gaji
//          berdasarkan jam kerja yang diberikan. Method ini abstrak.

// Buatlah juga kelas Programmer yang merupakan turunan dari Employee, yang mengoverride method int calculateSalary(int workHour) dengan aturan:

//     150 jam pertama, programmer mendapat gaji 100.000 per jam
//     Setelah 150 jam pertama, programmer mendapat gaji 10.000 per jam
//     Jika programmer sudah menikah, ia mendapat tambahan gaji 4.000.000

// Untuk lebih jelasnya, perhatikan tabel berikut: 

abstract class Employee {
    protected boolean hasMarried;

    public Employee() {
        hasMarried = false;
    }

    public void setHasMarried(boolean hM) {
        this.hasMarried = hM;
    }

    abstract public int calculateSalary(int workHour);
}