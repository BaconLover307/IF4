public class mainStack {
    public static void main(String args[]) {
        Stack s1 = new Stack(5);
        // Stack s2 = new Stack();
        for (int i = 0; i<5; i++) {
            s1.push(i);
        }
        for (int i = 0; i<5; i++) {
            int out;
            out = s1.pop();
            System.out.println(out);
        }


    }
}