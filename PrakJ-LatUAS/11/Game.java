// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 29-04-2020
// Topik 		: API

import java.util.*;

class Game {
    static void run(String[] hojun, String[] qila) {
        Map<String, Integer> map = new HashMap<String, Integer>();
        for (String a : hojun) {
            Integer freq = map.get(a);
            map.put(a, (freq == null) ? 1 : freq + 1);
        }
        for (String a : qila) {
            Integer freq = map.get(a);
            map.put(a, (freq == null) ? 0 : freq - 1);
        }
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            if (entry.getValue() > 0) {
                for (int i = 1; i <= entry.getValue(); i++) {
                    System.out.println(entry.getKey());
                }
            }
        }
    }
}