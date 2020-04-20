public class PlayerJoining extends Thread {
    private OnPlayerJoiningListener listener;

    public PlayerJoining(OnPlayerJoiningListener listener){
        this.listener = listener;
    }

    public void run(){
        try{
            Thread.sleep(2000);
        } catch (Exception e){
            System.out.println(e.getMessage());
        }
        listener.onPlayerJoin();
    }

    public interface OnPlayerJoiningListener{
        void onPlayerJoin();
    }
}