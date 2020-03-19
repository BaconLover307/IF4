// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 19-03-2020
// File 		: Cow.java

class Cow extends Animal {
    public Cow() {
        super(4);
    }

    public void eat(String food) {
        if (food.equals("grass")) {
            this.hungry = false;
        }
    }

    public void run() {
        super.run();
        System.out.println("Cow is running");
    }
}