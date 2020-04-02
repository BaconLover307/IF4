// Nama     : Gregorius Jovan Kresnadi
// NIM      : 13518135
// Tanggal  : 02-04-2020
// Topik    : Design Pattern

public class PizzaMain {
    public static void main(String args[]) {
        Pizza p = new PizzaBuilder()
        .crust("Cheesy Bites")
        .addTopping("Meat Lovers")
        .addTopping("Tuna Melt")
        .size("large")
        .build();
        System.out.println("Diameter = " + p.getDiameter());
        System.out.println("Crust = " + p.getCrust());
        System.out.println("Toppings = " + p.getToppingIngredients());
        System.out.println("Price = " + p.getPrice());
    }
}