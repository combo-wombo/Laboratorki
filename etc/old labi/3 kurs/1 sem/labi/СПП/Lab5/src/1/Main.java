public class Main {
    public static void main(String[] args) {
        Model model = new Model("x77", 360, "new version.");
        model.SetPrice(333);
        model.Print();
    }
}

class Model extends SamsungMobile{
    private String description;

    public Model(String model, int price, String description){
        super(model, price);
        this.description = description;
    }

    public void SetDescription(String description){
            this.description = description;
    }

    public String GetDescription(){
            return this.description;
    }

    public void Print(){
            System.out.println("Model: "+this.GetTitle()+"\nPrice: "+this.GetPrice()+"\nDesription: "+this.description+"\n\n");
    }
}
interface IMobile{
    String GetTitle();
    int GetPrice();
    void Print();
}
abstract class SamsungMobile implements IMobile{
    private String model;
    private int price;
    
    protected SamsungMobile(String model, int price) {
            this.model = model;
            this.price = price;
    }
    
    protected void SetPrice(int price) {
            this.price = price;
    }
    
    public int GetPrice() {
            return this.price;
    }
    
    public String GetTitle() {
            return "Samsung "+this.model;
    }
    
    public void Print(){
            System.out.println("Model: Samsung "+this.model+"\nPrice: "+this.price+"\n\n");
    }
}