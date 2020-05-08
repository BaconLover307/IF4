public class PizzaMain {
    
    public static void main(String args[]){
        Pizza mine = new PizzaBuilder()
            .crust("Cheesy Bites")
            .size("large")
            .addTopping("Meat Lovers")
            // .crust("Original")
            .addTopping("Tuna Melt")
            // .size("small")
            .build();
        System.out.println(mine.getCrust());
        System.out.println(mine.getDiameter());
        System.out.println(mine.getToppingIngredients());
        System.out.println(mine.getPrice());
    }

    
}