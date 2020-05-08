import java.util.HashMap;
import java.util.Map;

public class Game1 {
    // private HashMap<String, Integer> map;

    // public Game1() {
    //     map = new HashMap<String, Integer>();
    // }
    
    public static void run(String[] hojun, String[] qila) {
        HashMap<String, Integer> map = new HashMap<>();
        for (String h: hojun) {
            Integer freq = map.get(h);
            map.put(h, (freq == null) ? 1 : freq+1);
        }

        for (String q: qila) {
            Integer freq = map.get(h);
            map.put(h, (freq == null) ? 0 : freq-1);
        }

        for (Map.Entry<String, Integer> kata : map.entrySet()) {
            for (int i = 0; i<kata.getValue(); i++) {
                System.out.println(kata.getKey());
        }
    }

    }
}