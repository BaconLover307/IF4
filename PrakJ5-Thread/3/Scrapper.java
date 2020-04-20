import java.util.ArrayList;

class Scrapper implements ScrapperThread.OnGetPriceListener {
    private ArrayList<String> urlList;

    public Scrapper() {
        urlList = new ArrayList<String>();
    }

    public void addUrl(String url) {
        urlList.add(url);
    }

    public synchronized int scrapLowestPrice() {
        // Kode berikut masih melakukan scrap ke banyak website
        // secara sekuensial. Agar lebih cepat, ubahlah kode di bawah ini
        // menjadi paralel menggunakan wait dan notify, dengan membuat
        // instance ScrapperThread
        // Hint: baca materi praktikum
        int lowest = Integer.MAX_VALUE;
        
        for (String url : urlList) {
            Website website = new Website(url);
            int currInt = website.getPrice();
            lowest = (lowest > currInt) ? currInt : lowest;
        }
        return lowest;
    }

}
