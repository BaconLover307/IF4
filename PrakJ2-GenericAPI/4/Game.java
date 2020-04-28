// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 26-03-2020
// Topik 		: API

import java.util.*;

public class Game {

    public static void run(String[] hojun, String[] qila) {
        Map<String, Integer> h = new HashMap<String, Integer>();
        for (String a : hojun) {
            Integer freq = h.get(a);
            h.put(a, (freq == null) ? 1 : freq++);
        }

        for (String a : qila) {
            Integer freq = h.get(a);
            h.put(a, (freq == null) ? 0 : freq--);
        }

        for (Map.Entry<String, Integer> a : h.entrySet()) {
            if (a.getValue()>0) {
                for (int i =1; i <= a.getValue(); i++) {
                    System.out.println(a.getKey());
                }
            }
        }
    }
}
