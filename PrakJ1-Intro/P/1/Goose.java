// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 19-03-2020
// File 		: Goose.java

class Goose {
    private String name;
    private int honk;

    public Goose() {
        name = "Horrible";
        honk = 1;
    }

    public Goose(String name, int honk) {
        this.name = name;
        this.honk = honk;
    }

    public void steal(String thing) {
        System.out.println(this.name + " steals " + thing);
    }

    public String toString() {
        String out;
        out = this.name + " goose says";
        for (int i = 0; i<honk; i++) {
            out += " honk";
        }
        return out;
    }

}
