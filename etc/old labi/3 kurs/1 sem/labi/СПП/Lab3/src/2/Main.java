import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Main{
    public static void main(String[] args) {
        Menu menu = new Menu();
    }
    public static class Menu{
        static boolean working = true;
        public Menu(){
            Scanner keyboard = new Scanner(System.in);
            while (working){
                System.out.println("============================================================");
                System.out.println("Menu: ");
                System.out.println("0: Load apartments.");
                System.out.println("1: Print all apartments.");
                System.out.println("2: Show occupied apartments.");
                System.out.println("3: Show available apartments.");
                System.out.println("4: Find suitable apartment.");
                System.out.println("5: Toggle apartment occupation.");
                System.out.println("6: Show specific apartment (room amount).");
                System.out.println("7: Show specific apartment (room amount and floor range).");
                System.out.println("8: Show specific apartment (area is more than X).");
                System.out.println("9: Exit.");
                System.out.println("============================================================");

                System.out.print("Input: ");
                int input = keyboard.nextInt();

                switch (input) {
                    case (0) -> {
                        Menu.PrintEmpty();
                        System.out.print("Enter filename: ");
                        String filename = keyboard.next();
                        Bureau.ReadFile(filename);
                    }
                    case (1) -> {
                        Menu.PrintEmpty();
                        Bureau.Print();
                    }
                    case (2) -> {
                        Menu.PrintEmpty();
                        Bureau.PrintOccupation(true);
                    }
                    case (3) -> {
                        Menu.PrintEmpty();
                        Bureau.PrintOccupation(false);
                    }
                    case (4) -> {
                        Menu.PrintEmpty();
                        System.out.print("Enter rooms amount: ");
                        int rooms = keyboard.nextInt();
                        System.out.print("Enter floor: ");
                        int floor = keyboard.nextInt();
                        System.out.print("Enter area: ");
                        int area = keyboard.nextInt();
                        Bureau.PrintSuitable(rooms, floor, area);
                    }
                    case (5) -> {
                        Menu.PrintEmpty();
                        Bureau.Print();
                        System.out.print("Enter apartment index to toggle occupation: ");
                        int index = keyboard.nextInt();
                        Bureau.OccupationToggle(index);
                    }
                    case (6) -> {
                        Menu.PrintEmpty();
                        System.out.print("Enter room amount: ");
                        int rooms = keyboard.nextInt();
                        Bureau.PrintRooms(rooms);
                    }
                    case (7) -> {
                        Menu.PrintEmpty();
                        System.out.print("Enter rooms: ");
                        int rooms = keyboard.nextInt();
                        System.out.print("Enter minfloor: ");
                        int minfloor = keyboard.nextInt();
                        System.out.print("Enter maxfloor: ");
                        int maxfloor = keyboard.nextInt();
                        Bureau.PrintRoomsNFloors(rooms, minfloor, maxfloor);
                    }
                    case (8) -> {
                        Menu.PrintEmpty();
                        System.out.print("Enter area: ");
                        int area = keyboard.nextInt();
                        Bureau.PrintArea(area);
                    }
                    case (9) -> {
                        System.out.println("Exit");
                        working = false;
                    }
                    default -> {
                        Menu.PrintEmpty();
                        System.out.println("===!=== Not an option. Try again. ===!===");
                    }
                }
            }
        }
        private static void PrintEmpty(){
            System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public static class Apartment{
        int rooms;   int area;   int floor;   String address;   double price;   boolean occupation;

        public Apartment(){
            this.rooms = 1;
            this.area = 50;
            this.floor = 1;
            this.address = "Undefined";
            this.price = 0;
            this.occupation = false;
        }
        public Apartment(int rooms, int area, int floor, String address, double price, boolean occupation){
            this.rooms = rooms; this.area = area; this.floor = floor; this.address = address; this.price = price; this.occupation = occupation;
        }

        public String toString(){
            return this.rooms + " | " + this.area + " | " + this.floor + " | " + this.address + " | " + this.price + " | " + this.occupation;
        }
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public static class Bureau{
        static List<Apartment> AptList = new ArrayList<>();
        static List<String> AptListFile = new ArrayList<>();
        static boolean fileLoaded = false;

        public static void ReadFile(String file){
            try {
                Scanner scnr = new Scanner(new FileReader("C:\\Files\\" + file));
                String str;
                AptList.clear();
                AptListFile.clear();
                while (scnr.hasNextLine()) {
                    str = scnr.nextLine();
                    AptListFile.add(str);
                }
                fileLoaded = true;
                System.out.println("File read success!");
            } catch (FileNotFoundException e) {
                try {
                    File newfile = new File("C:\\Files\\" + file);
                    if (newfile.createNewFile()) {
                        System.out.println("No such file: " + newfile.getName() + ", creating new.");
                        fileLoaded = true;
                    }
                } catch (IOException ex) {
                    System.out.println("An error occurred (1).");
                    e.printStackTrace();
                }
            }
            //DBGPrintFile();
            SplitIntoApt();
        }
        public static void WriteFile(String filename){
            String contents = "";
            if (AptList.isEmpty()){
                System.out.println("(Write err) Database is empty. Nothing to write.");
                return;
            }
            for (Apartment i : AptList) {
                contents += i.toString() + "\n";
            }
            String[] file_arr = contents.split("\n");
            try {
                FileWriter fstream = new FileWriter("C:\\Files\\" + filename, false);
                BufferedWriter out = new BufferedWriter(fstream);
                for (int i = 0; i < file_arr.length; i++) {
                    out.write(file_arr[i]);
                    if (i != file_arr.length - 1) {
                        out.write("\n");
                    }
                }
                out.close();
            } catch (Exception e) {
                System.err.println("Error while writing to file: " +
                        e.getMessage());
            }
            System.out.println("Write successful.");
        }
        public static void SplitIntoApt(){
            String[] splitString;
            for (String i : AptListFile){
                splitString = i.split("" + " \\| ");
                Apartment newApt = new Apartment(
                        Integer.parseInt(splitString[0]),
                        Integer.parseInt(splitString[1]),
                        Integer.parseInt(splitString[2]),
                        splitString[3],
                        Double.parseDouble(splitString[4]),
                        Boolean.parseBoolean(splitString[5])
                );
                AptList.add(newApt);
            }
        }
        //public static void DBGPrintFile(){
        //    //DBG
        //    System.out.print("DBG Contents: \n");
        //    for (String i : AptListFile){
        //        System.out.println("newprint :" + i);
        //    }
        //}
        public static void AddApt(Apartment apt){
            if (!fileLoaded){System.out.println("(no file loaded");}
            AptList.add(apt);
        }
        public static void DeleteApt(Apartment apt){
            if (!fileLoaded){System.out.println("(no file loaded");}
            if(!AptList.remove(apt)){
                System.out.println("No such apartment in the Bureau database.");
            }
        }
        public static void Print(int index){
            System.out.println("Apartment at index " + index + ": ");
            Apartment apt = AptList.get(index);
            System.out.println(index + ": " + apt);
        }
        public static void Print(){
            if (!fileLoaded){System.out.println("(no file loaded)"); return;}
            System.out.print("All apartments: \n");
            int count = 0;
            for (Apartment apt : AptList){
                System.out.println(count + " :" + apt);
                count++;
            }
            if (count == 0){System.out.println("empty.");}
        }
        public static void PrintOccupation(boolean isOccupated){
            if (isOccupated){
                Bureau.PrintSorted("", "", "", "", "", "+", 0);
            } else {
                Bureau.PrintSorted("", "", "", "", "", "-", 0);
            }
        }
        public static void PrintSuitable(int rooms, int floor, int area){
            Bureau.PrintSorted(Integer.toString(rooms), Integer.toString(area), Integer.toString(floor), "", "", "", 1);
        }
        public static void OccupationToggle(int index){
            System.out.println("Toggling occupation at index " + index + ": ");
            Apartment apt = AptList.get(index);
            if(apt.occupation){
                System.out.println(index + ": " + apt + " -> false");
                apt.occupation = false;
            } else {System.out.println(index + ": " + apt + " -> true"); apt.occupation = true; }
        }
        public static void PrintRooms(int rooms){
            System.out.println("Apartments with " + rooms + " rooms: ");
            int count = 0;
            for (Apartment apt : AptList){
                if (apt.rooms == rooms){
                    System.out.println(count + ": " + apt);
                    count++;
                }
            }
            if (count == 0){System.out.println("empty.");}
        }
        public static void PrintRoomsNFloors(int rooms, int minfloor, int maxfloor){
            System.out.println("Apartments with " + rooms + " rooms and starting from " + minfloor + " floor through " + maxfloor + " floor: ");
            int count = 0;
            for (Apartment apt : AptList){
                if (apt.rooms == rooms && apt.floor >= minfloor && apt.floor <= maxfloor){
                    System.out.println(count + ": " + apt);
                    count++;
                }
            }
            if (count == 0){System.out.println("empty.");}
        }
        public static void PrintArea(int area){
            System.out.println("Apartments with area more than " + area + ": ");
            int count = 0;
            for (Apartment apt : AptList){
                if (apt.area >= area){
                    System.out.println(count + ": " + apt);
                    count++;
                }
            }
            if (count == 0){System.out.println("empty.");}
        }
        private static void PrintSorted(String rooms, String area, String floor, String address, String price, String occupation, int mode){
            int count = 0;
            if (mode == 0) {
                if (occupation.equals("+")) {
                    System.out.println("Occupated apartments:");
                    for (Apartment apt : AptList) {
                        if (apt.occupation) {
                            System.out.println(count++ + ": " + apt);
                        }
                    }
                    if (count==0){System.out.println("Empty.");}
                }
                if (occupation.equals("-")) {
                    System.out.println("Available apartments:");
                    for (Apartment apt : AptList) {
                        if (!apt.occupation) {
                            System.out.println(count++ + ": " + apt);
                        }
                    }
                    if (count==0){System.out.println("Empty.");}
                }
            }
            if (mode == 1) {
                System.out.println("Suitable apartments:");
                for (Apartment apt : AptList) {
                    if (apt.rooms == Integer.parseInt(rooms) && apt.floor == Integer.parseInt(floor)) {
                        if (apt.area > Integer.parseInt(area) - 10 && apt.area < Integer.parseInt(area) + 10) {
                            System.out.println(count++ + ": " + apt);
                        }
                    }
                }
                if (count==0){System.out.println("empty.");}
            }
        }
    }
}
