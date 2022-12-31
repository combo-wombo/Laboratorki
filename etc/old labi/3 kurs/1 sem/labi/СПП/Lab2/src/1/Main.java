import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main{
    public static void main(String[] args) throws IOException{

        String path_to_files = "C:\\Users\\Student\\IdeaProjects\\lab2_1\\src\\";
        BufferedReader file1 = new BufferedReader(new FileReader(path_to_files + "file1.txt"));
        BufferedReader file2 = new BufferedReader(new FileReader(path_to_files + "file2.txt"));

        String line1 = file1.readLine();
        String line2 = file2.readLine();

        boolean equal = true;
        int line = 1;
        int character = 1;

        while (line1 != null || line2 != null)
        {
            if(line1 == null || line2 == null)
            {
                equal = false;
                break;
            }

            else if(! line1.equalsIgnoreCase(line2))
            {
                equal = false;
                break;
            }

            line1 = file1.readLine();
            line2 = file2.readLine();
            line++;

        }

        if(equal){
            System.out.println("\n--- No differences found. ---");
        } else {
                for (int i = 0; i < line1.length(); i++){
                    if (line1.charAt(i) != line2.charAt(i)){
                        character = i + 1; break;
                    }
                }
                System.out.println("Files are different on line : " + line + " , character : " + character);
                System.out.println("File1 : " + line1 + "\nFile2 : " + line2);

                for (int i = 0; i < character + 7; i++){  System.out.print(" ");  }
                System.out.print("^");
        }

        file1.close();
        file2.close();
    }
}