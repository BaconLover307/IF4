public class ScrapperThread extends Thread {
    private OnGetPriceListener listener;

    public ScrapperThread(OnGetPriceListener listener){
        this.listener = listener;
    }

    public void run() {
        try {
            wait();
            listener.scrapLowestPrice();
            notify();
        } catch (Exception e) {
        }
    }

    public interface OnGetPriceListener {
        int scrapLowestPrice(); 
    } 
}