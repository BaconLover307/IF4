// Nama     : Gregorius Jovan Kresnadi
// NIM      : 13518135
// Tanggal  : 16-04-2020
// Topik 	: Reflection

import java.lang.reflect.*;

public class AssistantDecoder {
    private Assistant a;

    AssistantDecoder(Assistant assistant) {
        this.a = assistant;
    }

    public void addPersonToRecommendations(String name) throws Exception {
        Class c = this.a.getClass();
        Method m = c.getDeclaredMethod("addPersonToRecommendations", String.class);
        m.setAccessible(true);
        m.invoke(this.a, name);
    }
    
    public int getSalary() throws Exception {
        Class c = this.a.getClass();
        Field f = c.getDeclaredField("salary");
        f.setAccessible(true);
        int sal = (int) f.get(this.a);
        return sal;
    }
}