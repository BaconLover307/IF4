import java.util.ArrayList;

class Scrapper implements ScrapperThread.ScrapperListener {
    private ArrayList<String> urlList;
    private int low, cnt;

    public Scrapper() {
        urlList = new ArrayList<String>();
        low = Integer.MAX_VALUE;
        cnt = 0;
    }

    public void addUrl(String url) {
        urlList.add(url);
    }

    public synchronized void onScrapeListener(int price) {
        int prev = this.cnt;
        this.cnt = prev + 1;
        // this.low = Math.min(this.low, price);
        if (price < low) {
            low = price;
        }
        this.notify();
    }

    public int scrapLowestPrice() {
        // Kode berikut masih melakukan scrap ke banyak website
        // secara sekuensial. Agar lebih cepat, ubahlah kode di bawah ini
        // menjadi paralel menggunakan wait dan notify, dengan membuat
        // instance ScrapperThread
        // Hint: baca materi praktikum
        for (String url : urlList) {
            Thread thread = new ScrapperThread(this, url);
            thread.start();
        }
        while(this.cnt < urlList.size()) {
            try{
                this.wait();
            } catch(Exception e) {}
        }
        return this.low;
    }
}
