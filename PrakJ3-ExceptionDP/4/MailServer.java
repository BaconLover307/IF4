// Nama     : Gregorius Jovan Kresnadi
// NIM      : 13518135
// Tanggal  : 02-04-2020
// Topik 		: Design Pattern

// import java api jika diperlukan
import java.util.*;

public class MailServer implements EventChannel {
  private Map<String, List<Subscriber>> mailingList;

  // menginisiasi daftar subscriber
  public MailServer() {
    this.mailingList = new HashMap<>();
  }

  // tambahkan s sebagai subscriber ke topic yang diberikan
  public void addSubscriber(String topic, Subscriber s) {
    mailingList.putIfAbsent(topic,new ArrayList<Subscriber>());
    mailingList.get(topic).add(s);
  }

  public void sendEvent(String topic, Event event) {
    // untuk setiap subscriber s yang sudah subscribe ke topic yang diberikan,
    // panggil s.onEvent(event)
    if(mailingList.get(topic) != null) {
      for(Subscriber sub : mailingList.get(topic)) {
        sub.onEvent(event);
      }
    }
  }
}