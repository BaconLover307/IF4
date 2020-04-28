import java.util.Map;
import java.util.TreeMap;
import java.util.stream.Collectors;
import java.lang.reflect.*;

class JSONWriter {
    private Object o;

    public JSONWriter(Object o) {
        this.o = o;
    }

    public String mapToJSON(Map<String, String> jsonFieldMap) {
        String jsonString = jsonFieldMap
            .entrySet()
            .stream()
            .map(entry -> "\"" + entry.getKey() + "\":\"" + entry.getValue() + "\"")
            .collect(Collectors.joining(","));

        return "{" + jsonString + "}";
    }

    public String toString() {
        Map<String, String> jsonFieldMap = new TreeMap<>();
        // TODO:
        // Untuk setiap field di kelas o, periksa apakah memiliki anotasi dengan
        // field.isAnnotationPresent(JSONField.class).
        // Jika ada, tambahkan entry ke jsonFieldMap dengan <key,value> =
        //   key = nama field
        //   value = nilai dari field
        // ...lengkapi di sini

        for (Field f : o.getClass().getDeclaredFields()) {
            if (!f.isAnnotationPresent(JSONField.class)) {
                continue;
            }
            f.setAccessible(true);
            try {
                jsonFieldMap.put(f.getName(), f.get(o).toString());
            } catch (Exception e) {
            }
        }

        return mapToJSON(jsonFieldMap);
    }
}