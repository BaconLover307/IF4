// Nama     : Gregorius Jovan Kresnadi
// NIM      : 13518135
// Tanggal  : 16-04-2020
// Topik 	: Thread
 
// main.java
public class main {
    public static void main(String[] argv){
        // Thread ttd = new Game();
        Game fortnite = new Game();//(Game) ttd;
        PlayerJoining pj = new PlayerJoining(fortnite);
        try{
            fortnite.onPlayerJoin();
            fortnite.start();
            fortnite.onPlayerJoin();
            fortnite.onPlayerJoin();
            fortnite.onPlayerJoin();
            fortnite.onPlayerJoin();
            fortnite.onPlayerJoin();
            fortnite.onPlayerJoin();
            fortnite.onPlayerJoin();
            fortnite.onPlayerJoin();
            fortnite.onPlayerJoin();
        }
        catch (Exception e){
            System.out.println(e.getMessage());
        }
    }
}