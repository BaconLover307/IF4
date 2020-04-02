package Materi;

class Main {
    public static void main(String args[]) {
        Vector v = new Vector(10);
        v.push(19);
        v.push(29);

        try {
            System.out.println(v.get(1));
            System.out.println(v.get(2));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}