// Nama     : Gregorius Jovan Kresnadi
// NIM      : 13518135
// Tanggal  : 02-04-2020
// Topik    : Design Pattern

import java.util.Set;
import java.util.TreeSet;

class PizzaBuilder {
    private String crust;
    private Set<String> toppingIngredients;
    private int diameter;
    private int price;

    public PizzaBuilder() {
        this.toppingIngredients = new TreeSet<String>();
        this.diameter = 35;
        this.crust = "Original";
        this.price = this.diameter * 15;
    }

    public PizzaBuilder size(String s) { // Change Price??
        if (s.equals("small")) this.diameter = 25;
        else if (s.equals("medium")) this.diameter = 35;
        else if (s.equals("large")) this.diameter = 40;
        return this;
    }

    public PizzaBuilder crust(String c) {
        this.crust = c;
        // if (c.eq uals("Cheesy Bites")) this.price += 10;
        // else if (c.equals("Stuffed")) this.price += 20;
        return this;
    }

    public PizzaBuilder addTopping(String t) {
        if (t.equals("Meat Lovers")) {
            this.toppingIngredients.add("beef");
            this.toppingIngredients.add("mozarella");
        } else if (t.equals("Tuna Melt")) {
            this.toppingIngredients.add("tuna");
            this.toppingIngredients.add("corn");
            this.toppingIngredients.add("mozarella");
        } else if (t.equals("Supreme")) {
            this.toppingIngredients.add("pepperoni");
            this.toppingIngredients.add("beef");
            this.toppingIngredients.add("mushroom");
            this.toppingIngredients.add("pineapple");
        }
        return this;
    }

    public Pizza build() {
        Pizza pizza = new Pizza();
        pizza.setDiameter(this.diameter);
        pizza.setCrust(this.crust);
        for (String topping : this.toppingIngredients) {
            pizza.addToppingIngredient(topping);
        }
        int crustPrice = 0;
        if (pizza.getCrust().equals("Cheesy Bites")) crustPrice = 10;
        else if (pizza.getCrust().equals("Stuffed")) crustPrice = 20;
        pizza.setPrice(15*pizza.getDiameter() + 10*pizza.getToppingIngredients().size() + crustPrice);
        return pizza;
    }
}