import java.util.Timer;
import java.util.TimerTask;

public class Player {
    protected Timer timer;
    protected long timeout;
    protected long lastActive;

    public Player(Timer timer, long timeout) {
        this.timer = timer;
        this.timeout = timeout;
        this.lastActive = System.nanoTime();
        this.timer.schedule(new RemindTask(), timeout, timeout);
        // TODO: Me-set timer untuk menginvoke checkLastActive
        //       dengen delay {timeout} ms
        //       dan diinvoke tiap {timeout} ms.
    }

    class RemindTask extends TimerTask {
        public void run() {
            checkLastActive();
        }
    }

    public void checkLastActive() {
        if (lastActive < System.nanoTime() - timeout) {
            logout();
            timer.cancel();
        }
        // TODO: Membandingkan apakah lastActive < waktu sekarang - timeout
        //       Jika ya, panggil logout dan cancel timer agar timer berhenti.
        //       Gunakan System.nanoTIme() untuk mendapat waktu sekarang.
    }

    public void logout() {
        System.out.println("logout");
    }

    public void click() {
        this.lastActive = System.nanoTime();
        // TODO: Update lastActive menjadi waktu sekarang
    }
}
