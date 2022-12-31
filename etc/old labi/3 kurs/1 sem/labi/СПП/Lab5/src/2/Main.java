import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        ArrayList<Pet> pets = new ArrayList<>();
        pets.add(new Dog("Bobik", "Black", true));
        pets.add(new Cat("Simon", "White", true));
        pets.add(new Parrot("Kesha", "Yellow", false));

        for (Pet pet : pets) {
            pet.DetData();
        }
    }
}
abstract class Pet
{
    private String name;
    private String color;
    protected Pet(String name, String color)    {
        this.name = name;
        this.color = color;
    }
    public void SetName(String name)    {
        this.name = name;
    }
    public void SetColor(String color)    {
        this.color = color;
    }
    public String GetName()    {
        return this.name;
    }
    public String GetColor()    {
        return this.color;
    }
    public abstract void DetData();
}



class Parrot extends Pet{
    private boolean IsTalking;
    public Parrot(String name, String color, boolean isTalking){
        super(name, color);
        this.IsTalking = isTalking;
    }
    public void SetIsTalking(boolean isTalking){
        this.IsTalking = isTalking;
    }
    private boolean GetIsTalking(){
        return this.IsTalking;
    }
    public void DetData(){
        System.out.println("--Parrot--\nName: "+this.GetName()+"\nColor: "+this.GetColor()+"\nHousehold: "+this.GetIsTalking());
    }
}

class Dog extends Pet{
    private boolean IsTrained;
    public Dog(String name, String color, boolean isTrained){
        super(name, color);
        this.IsTrained = isTrained;
    }
    public void SetIsTrained(boolean isTrained) {
        this.IsTrained = isTrained;
    }
    private boolean GetIsTrained() {
        return this.IsTrained;
    }
    public void DetData() {
        System.out.println("--Dog--\nName: "+this.GetName()+"\nColor: "+this.GetColor()+"\nHousehold: "+this.GetIsTrained());
    }
}

class Cat extends Pet {
    private boolean IsHousehold;
    public Cat(String name, String color, boolean isHousehold){
        super(name, color);
        this.IsHousehold = isHousehold;
    }
    public void SetIsHousehold(boolean isHousehold) {
        this.IsHousehold = isHousehold;
    }
    private boolean GetIsHousehold() {
        return this.IsHousehold;
    }
    public void DetData() {
        System.out.println("--Cat--\nName: "+this.GetName()+"\nColor: "+this.GetColor()+"\nHousehold: "+this.GetIsHousehold());
    }
}