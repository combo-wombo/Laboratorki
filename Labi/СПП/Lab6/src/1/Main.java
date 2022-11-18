public class Main {
    public static void main(String[] args) {
        Order.Builder v_Builder = Order.Builder.f_new_instance();
        v_Builder.f_set_dish(new Burger(12.99, "Chicken Burger", 400.0, Burger.BurgerType.CHICKEN));
        v_Builder.f_set_drink(new ColdDrink(4.38, "Coca-Cola", 200.0, ColdDrink.ColdDrinkType.COLA));
        v_Builder.f_set_need_to_pack(true);
        v_Builder.f_set_pack_price(0.89);

        Order c_Order = v_Builder.f_build();
        System.out.println("Total price: " + c_Order.f_get_total_price());
    }
}
class Order{
    private Dish m_Dish;
    private Drink m_Drink;

    private double m_PackPrice;
    private boolean m_NeedToPack;

    private double m_TotalPrice;

    public Order(Builder c_Builder) {
        m_Dish = c_Builder.m_Dish;
        m_Drink = c_Builder.m_Drink;
        m_PackPrice = c_Builder.m_PackPrice;
        m_NeedToPack = c_Builder.m_NeedToPack;
        m_TotalPrice = c_Builder.m_TotalPrice;
    }
    Builder builder = new Builder();

    public Dish f_get_dish() {
        return m_Dish;
    }

    public Drink f_get_drink() {
        return m_Drink;
    }

    public double f_get_pack_price() {
        return m_PackPrice;
    }

    public boolean f_get_need_to_pack() {
        return m_NeedToPack;
    }

    public double f_get_total_price() {
        return m_TotalPrice;
    }

    public static class Builder {
        public Dish m_Dish = null;
        public Drink m_Drink = null;
        public double m_PackPrice = 0.0;
        public boolean m_NeedToPack = false;
        public double m_TotalPrice = 0.0;
        public static Builder f_new_instance() {
            return new Builder();
        }
        public Builder(){
        }
        public void f_set_dish(Dish c_Dish) {
            m_Dish = c_Dish;
            m_TotalPrice = f_total_price();
        }
        public void f_set_drink(Drink c_Drink) {
            m_Drink = c_Drink;
            m_TotalPrice = f_total_price();
        }
        public void f_set_pack_price(double c_PackPrice) {
            m_PackPrice = c_PackPrice;
            m_TotalPrice = f_total_price();
        }
        public void f_set_need_to_pack(boolean c_NeedToPack) {
            m_NeedToPack = c_NeedToPack;
            m_TotalPrice = f_total_price();
        }
        public double f_total_price() {
            double v_TotalPrice = 0.0;
            if (m_Dish != null) {
                v_TotalPrice += m_Dish.f_get_price();
            }
            if (m_Drink != null) {
                v_TotalPrice += m_Drink.f_get_price();
            }
            if (m_NeedToPack) {
                v_TotalPrice += m_PackPrice;
            }
            return v_TotalPrice;
        }
        public Order f_build() {
            return new Order(this);
        }
    }
}

abstract class Dish extends Product{
    private double m_Weight = 0.0;
    private Type m_Type;
    public Dish(double c_Price, String c_Name, double c_Weight, Type c_Type){
        super(c_Price, c_Name);
        m_Weight = c_Weight;
        m_Type = c_Type;
    }
    public double f_get_weight(){
        return m_Weight;
    }
    public void f_set_wight(double c_Weight){
        m_Weight = c_Weight;
    }
    public Type f_get_type(){
        return m_Type;
    }
    public void f_set_type(Type c_Type){
        m_Type = c_Type;
    }
    public enum Type {
        BURGER,
        SALAD
    }
}

abstract class Drink extends Product{
    private double m_Volume = 0.0;
    private Type m_Type;
    public Drink(double c_Price, String c_Name, double c_Volume, Type c_Type){
        super(c_Price, c_Name);
        m_Volume = c_Volume;
        m_Type = c_Type;
    }
    public double f_get_volume(){
        return m_Volume;
    }
    public void f_set_volume(double c_Volume){
        m_Volume = c_Volume;
    }
    public Type f_get_type(){
        return m_Type;
    }
    public void f_set_type(Type c_Type){
        m_Type = c_Type;
    }
    public enum Type {
        HOT,
        COLD
    }
}

class ColdDrink extends Drink{
    private ColdDrinkType m_ColdDrinkType;
    public ColdDrink(double c_Price, String c_Name, double c_Volume, ColdDrinkType c_ColdDrinkType){
        super(c_Price, c_Name, c_Volume, Drink.Type.HOT);
        m_ColdDrinkType = c_ColdDrinkType;
    }
    public ColdDrinkType f_get_cold_drink_type(){
        return m_ColdDrinkType;
    }
    public void f_set_cold_drink_type(ColdDrinkType c_ColdDrinkType){
        m_ColdDrinkType = c_ColdDrinkType;
    }
    public enum ColdDrinkType {
        COLA,
        PEPSI
    }
}

class Burger extends Dish{
    private BurgerType m_BurgerType;
    public Burger(double c_Price, String c_Name, double c_Weight, BurgerType c_BurgerType){
        super(c_Price, c_Name, c_Weight, Dish.Type.BURGER);
        m_BurgerType = c_BurgerType;
    }
    public BurgerType f_get_burger_type(){
        return m_BurgerType;
    }

    public void f_set_burger_type(BurgerType c_BurgerType){
        m_BurgerType = c_BurgerType;
    }
    public enum BurgerType {
        VEGAN,
        CHICKEN
    }
}

class Salad extends Dish{
    private SaladType m_SaladType;
    public Salad(double c_Price, String c_Name, double c_Weight, SaladType c_SaladType){
        super(c_Price, c_Name, c_Weight, Dish.Type.SALAD);
        m_SaladType = c_SaladType;
    }
    public SaladType f_get_salad_type(){
        return m_SaladType;
    }
    public void f_set_salad_type(SaladType c_SaladType){
        m_SaladType = c_SaladType;
    }
    public enum SaladType{
        VEGETABLE,
        SEAFOOD
    }
}

abstract class Product {
    private double m_Price = 0.0;
    private String m_Name = "";
    public Product(double c_Price, String c_Name) {
        m_Price = c_Price;
        m_Name = c_Name;
    }
    public double f_get_price() {
        return m_Price;
    }
    public void f_set_price(double c_Price) {
        m_Price = c_Price;
    }
    public String f_get_name() {
        return m_Name;
    }
    public void f_set_name(String c_Name) {
        m_Name = c_Name;
    }
}