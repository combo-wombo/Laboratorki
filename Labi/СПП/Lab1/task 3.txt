import java.util.Scanner;
public class Main{
    public static void main(String[] args)
    {
        Scanner sc= new Scanner(System.in);
        System.out.print("Enter a string: ");
        String mystring= sc.nextLine();

        mystring = abbreviate(mystring);
        System.out.println("Abbreviation: " + mystring);
    }

    public static String abbreviate(String str){
        String[] mylist = str.split(" ");
        str = "";
        for (String word : mylist){
            str = str + word.charAt(0);
        }
        return str;
    }
}