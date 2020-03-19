// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 19-03-2020
// File 		: Programmer.java

class Programmer extends Employee {
    public Programmer() {
        super();
    }

    public void setHasMarried(boolean hM) {
        this.hasMarried = hM;
    }

    public int calculateSalary(int workHour) {
        int gaji;
        if (workHour <= 150) {
            gaji = workHour*100000;
        } else {
            gaji = 150*100000 + (workHour-150) * 10000;
        }
        if (this.hasMarried) {
            gaji += 4000000;
        }
        return gaji;
    }

}