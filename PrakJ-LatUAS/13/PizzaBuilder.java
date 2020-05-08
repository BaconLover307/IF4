import java.util.*;

public class PizzaBuilder extends Pizza {
    public int size;
    public String crust;
    public Set<String> toppings;
    public Pizza piz;
    public int price;

    public PizzaBuilder() {
        piz = new Pizza();
        toppings = new TreeSet<String>();
        crust = "Original";
        size = 35;
        price = 0;
    }

    public PizzaBuilder size(String s) {
        if (s.equals("small")) {
            this.size = 25;
        } else if (s.equals("medium")) {
            this.size = 35;
        } else {
            this.size = 40;
        }
        return this;
    }

    public PizzaBuilder crust(String c) {
        crust = c;
        if (c.equals("Cheesy Bites")) {
            price = 10;
        } else if (c.equals("Stuffed")) {
            price = 20;
        } else {
            price = 0;
        }
        return this;
    }

    public PizzaBuilder addTopping(String t) {
        if (t.equals("Meat Lovers")) {
            toppings.add("beef");
            toppings.add("mozarella");
        } else if (t.equals("Tuna Melt")) {
            toppings.add("tuna");
            toppings.add("corn");
            toppings.add("mozarella");
        } else {
            toppings.add("pepperoni");
            toppings.add("beef");
            toppings.add("mushroom");
            toppings.add("pineapple");
        }
        return this;
    }

    public Pizza build() {
        price += 15*size;
        for (String s: toppings) {
            price += 10;
            piz.addToppingIngredient(s);
        }
        piz.setDiameter(size);
        piz.setCrust(crust);
        piz.setPrice(price);
        return piz;
    }
}