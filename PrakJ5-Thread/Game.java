import java.util.*;
import java.util.Timer;

public class Game implements PlayerJoining.OnPlayerJoiningListener{
    private int playerCount;
    public Game() {
        this.playerCount = 0;
    }
    @Override
    public synchronized void onPlayerJoin() {
        int prevPlayerCount = this.playerCount;
        this.playerCount = prevPlayerCount + 1;
        this.notify();
    }
    public synchronized void start() throws Exception {
        while (this.playerCount < 10) {
            this.wait(); // kode ini blocking, artinya prosesor tidak akan
                         // melanjutkan kecuali ada yang melakukan notify
        }
        System.out.println("starting game!");
    }
    
}