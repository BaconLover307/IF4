// Nama     : Gregorius Jovan Kresnadi
// NIM      : 13518135
// Tanggal  : 08-05-2020
// Topik 	: Design Pattern


// import java api jika diperlukan
import java.util.*;

public class MailServer implements EventChannel {
  // tambahkan properties jika perlu
  private Map<String, List<Subscriber>> mailingList;

  public MailServer() {
      // menginisiasi daftar subscriber
      this.mailingList = new HashMap<>();
  }

  public void addSubscriber(String topic, Subscriber s) {
        // tambahkan s sebagai subscriber ke topic yang diberikan
        mailingList.putIfAbsent(topic, new ArrayList<Subscriber>());
        mailingList.get(topic).add(s);
    }
    
    public void sendEvent(String topic, Event event) {
        // untuk setiap subscriber s yang sudah subscribe ke topic yang diberikan,
        // panggil s.onEvent(event)
        if (mailingList.get(topic) != null) {
            for (Subscriber s: mailingList.get(topic)) {
                s.onEvent(event);
            }
        }
    }
}
