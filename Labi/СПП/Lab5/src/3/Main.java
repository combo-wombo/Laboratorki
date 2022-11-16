import java.util.*;

public class Main {
    public static void main(String[] args) {
        User john = new User("John", 150);
        User mark = new User("Mark", 30);
        User usr1 = new User("User 1", 5);
        Admin admin = new Admin();

        PhoneStation.addUser(john, "+375");
        PhoneStation.addUser(mark, "+518");
        PhoneStation.addUser(usr1, "+672");
        PhoneStation.print();

        Service internet = new Service("internet", 20);

        admin.addServUser(internet, john);
        john.useServ();
        john.askNumber("+111");
        john.askDelService(internet);

        admin.checkUser(john);

        john.addBalance(-130);
        admin.checkUser(john);
    }
}

interface PrintableStatic{
    static public void print(){};
}

class PhoneStation implements PrintableStatic{
    static Map<String, User> phonebook = new HashMap<String, User>();
    static ArrayList<Service> servList = new ArrayList<>();
    static double call_price = 10.0;
    static public void changePrice(double price){
        PhoneStation.call_price = price;
        System.out.println("PhoneStation: new price is $"+PhoneStation.call_price+".");
    }
    static public void print(){
        if (!phonebook.isEmpty()) {
            System.out.println("PhoneStation: printing the phonebook.");
            for(Map.Entry<String, User> entry : phonebook.entrySet()) {
                String number = entry.getKey();
                User usr = entry.getValue();
                System.out.println("Number:  " + number + " - " + usr.name + ";");
            }
        } else {
            System.out.println("PhoneStation: the phonebook is empty.");
        }
    }
    static public void addUser(User user, String number){
        PhoneStation.phonebook.put(number, user);
        System.out.println("PhoneStation: added user "+user.name+" (number is "+number+").");
    }
    static public void delUser(User user){
        boolean removed = false;

        Iterator<Map.Entry<String, User> >
                iterator = PhoneStation.phonebook.entrySet().iterator();

        while (iterator.hasNext()) {
            Map.Entry<String, User> entry = iterator.next();
            if (user.name.equals(entry.getValue().name)) {
                iterator.remove();
                removed = true;
                System.out.println("PhoneStation: deleted user "+user.name+".");
            }
        }

        if (!removed){
            System.out.println("PhoneStation: (remove) couldn't find user "+user.name+".");
        }
    }
}
abstract class Citizen{
    String name;
    double money;
    String message;
    public Citizen(){
        this.name = "anonymous";
        this.money = 0.0;
        this.message = "...";
    }
    public Citizen(String name, double money, String message){
        this.name = name;
        this.money = money;
        this.message = message;
        System.out.println(this.name + ": my message is - "+message);
    }
}

class User extends Citizen{
    String need = "none";
    List<Service> servList = new ArrayList<>();
    public User(){
        this.name = "Unnamed";
        this.money = 0.0;
    }
    public User(String name, double money){
        this.name = name;
        this.money = money;
        System.out.println(this.name + ": hi, my name is "+this.name+" and i have $"+this.money+".");
    }
    public void print(){
        System.out.println(this.name + ": balance = $"+this.money+".");
    }
    public void addBalance(double amt){
        this.money += amt;
        System.out.println(this.name + ": new balance = $"+this.money+".");
    }
    public void talk(){
        if (PhoneStation.phonebook.containsValue(this)) {
            if (this.money >= PhoneStation.call_price) {
                System.out.println(this.name + ": is talking.");
                this.money -= PhoneStation.call_price;
                System.out.println(this.name + ": remaining balance = $" + money + ".");
            } else {
                System.out.println(this.name + ": not enough balance to talk.");
            }
        } else {
            System.out.println(this.name + ": i'm not in the phonebook.");
        }
    }
    public void useServ(){
        if (PhoneStation.phonebook.containsValue(this)) {
            double servicesFullPrice = 0;
            for (Service serv : this.servList) {
                servicesFullPrice += serv.price;
            }
            if (servicesFullPrice != 0) {
                if (this.money >= servicesFullPrice) {
                    System.out.println(this.name + ": is using services.");
                    this.money -= servicesFullPrice;
                    System.out.println(this.name + ": remaining balance = $" + money + ".");
                } else {
                    System.out.println(this.name + ": not enough balance to use services.");
                }
            }
        } else {
            System.out.println(this.name + ": i'm not in the phonebook.");
        }
    }
    public void askNumber(String number){
        if(number.length() > 1){
            this.need = "1" + number;
            System.out.println(this.name + ": asked to change number to "+number+".");
        }
    }
    public void askDelService(Service serv){
        this.need = "2" + serv.name;
        System.out.println(this.name + ": asked to delete service "+serv.name+".");
    }
}
interface IService{
    public void changePrice(double newPrice);
    public void showPrice();
}

class Service implements IService{
    String name;
    double price;
    public Service(String name, double price){
        this.name = name;
        this.price = price;
    }
    public void changePrice(double newPrice){
        this.price = newPrice;
        System.out.print(this.name+": new Price is "+this.price+".");
    }
    public void showPrice(){
        System.out.print(this.name+": price - $"+this.price+".");
    }
}

class Admin{
    public Admin(){
        System.out.println("Admin: admin created.");
    }
    public void addServStation(Service serv){
        if (!PhoneStation.servList.contains(serv)){
            PhoneStation.servList.add(serv);
            System.out.println("Admin: service " + serv.name + " added.");
        } else {
            System.out.println("Admin: service " + serv.name + " is already in PhoneStation.");
        }
    }
    public void addServUser(Service serv, User user){
        if (!user.servList.contains(serv)){
            user.servList.add(serv);
            System.out.println("Admin: service " + serv.name + " added to user "+user.name+".");
        } else {
            System.out.println("Admin: service " + serv.name + " is already in user "+user.name+".");
        }
    }
    public void checkUser(User user){
        System.out.println("Admin: checking services on user "+user.name+".");
        double servicesFullPrice = 0;
        for (Service serv : user.servList){
            servicesFullPrice += serv.price;
        }
        //if he can pay the bills
        if (user.money < 0 || user.money <= PhoneStation.call_price || user.money <= servicesFullPrice){
            PhoneStation.delUser(user);
            System.out.println("Admin: user "+user.name+ " couldn't pay the bills, removed.");
            return;
        }

        if(!user.need.equals("none")){
            if(user.need.charAt(0) == '1'){
                PhoneStation.delUser(user);
                PhoneStation.addUser(user, user.need.substring(1));
                System.out.println("Admin: changed user "+user.name+" number to " +user.need.substring(1)+ ".");
                user.need = "none";
            } else
            if (user.need.charAt(0) == '2'){
                boolean removed = false;
                for (Service serv : user.servList){
                    if (serv.name.equals(user.need.substring(1))){
                        user.servList.remove(serv);
                        System.out.println("Admin: removed service "+user.need.substring(1)+" from user "+user.name+".");
                        user.need = "none";
                        removed = true;
                        break;
                    }
                }
                if(!removed){
                    System.out.println("Admin: couldn't remove service "+user.need.substring(1)+" from user "+user.name+" (serv not found).");
                }
            }
        } else {
            System.out.println("Admin: no needs from user "+user.name+".");
        }
    }
}
