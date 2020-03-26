/* List API https://docs.oracle.com/javase/tutorial/collections/interfaces/list.html
adalah Collection yang urutan elemennya disesuaikan dengan urutan pemasukannya.
Implementasi List:
● ArrayList
● LinkedList
*/

import java.util.*;
public class Shuffle {
    public static void main(String[] args) {
        List<String>list = new ArrayList<String>();
        for (String a : args)
            list.add(a);
        Collections.shuffle(list, new Random());
        System.out.println(list);
    }
}