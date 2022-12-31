public class Main {
    public static void main(String[] args) {
        Word hello_ = new Word("hello");
        Word this_ = new Word("this");
        Word is_ = new Word("is");
        Word a_ = new Word("a");
        Word page_ = new Word("page");

        Page page1 = new Page(new Word[]{hello_, this_, is_, a_, page_});

        page1.printPage();
    }

    static class Word {
        String word;

        public Word(String word) {
            this.word = word;
        }

        public void printWord() {
            System.out.println(this.word);
        }
    }

    static class Page {
        String page;

        public Page(Word[] words) {
            page = "";
            for (Word word : words)  page += word.word + " ";
            page = page.trim();
        }

        public void printPage() {
            System.out.println(this.page);
        }
    }
}