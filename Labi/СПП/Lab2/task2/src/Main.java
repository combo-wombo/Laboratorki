import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.NoSuchFileException;
import java.nio.file.Paths;

public class Main{
    public static void main(String[] args) throws IOException {

        boolean arg_bytes, arg_lines, arg_numeric;
        String filename, prefix, file, newfilename;
        int num = 10;

        arg_bytes = arg_lines = arg_numeric = false;
        filename = prefix = "";

        if (args.length == 0){
            System.out.println("Arguments parse fail : no arguments (use --help to learn about usable parameters).");
            System.exit(1);
        }

        for (int i = 0; i<args.length; i++){
            ////help///////////////////////////////////////////////////////////////////////////////////////////
            if (args[i].equalsIgnoreCase("-h") | args[i].equalsIgnoreCase("--help")){
                System.out.println("Usage : split [-b OR -l <num>] [-d] [<filename.txt> [prefix]]");
                System.out.println("\nParameters : ");
                System.out.println("\t-b (--bytes) - divide the original file into multiple files that consist of <num> bytes from the original file.");
                System.out.println("\t-l (--lines) - split the file into multiple files that contain a specified amount of lines from the original.");
                System.out.println("\t-d (--numericprefixes) - the files will use a numeric prefix (00_ex.txt, 01_ex.txt, 02_ex.txt and so on).");
                System.out.println("\nExample : split -b 4 file1.txt -d");
                System.exit(0);
            }
            ////bytes//////////////////////////////////////////////////////////////////////////////////////////
            if (args[i].equalsIgnoreCase("-b") | args[i].equalsIgnoreCase("--bytes")) {
                arg_bytes = true;
                if (i+1 < args.length) {
                    try {
                        num = Integer.parseInt(args[i+1]);
                    }   catch (NumberFormatException nfe){
                        System.out.println("Arguments parse fail : first argument after -b (--bytes) arg is not an integer.");
                        System.exit(1);
                    }
                } else {
                    System.out.println("Arguments parse fail : no arguments after -b (--bytes).");
                    System.exit(1);
                }
            }
            ////lines//////////////////////////////////////////////////////////////////////////////////////////
            if (args[i].equalsIgnoreCase("-l") | args[i].equalsIgnoreCase("--lines")) {
                arg_lines = true;
                if (i+1 < args.length){
                    try {
                        num = Integer.parseInt(args[i+1]);
                    }   catch (NumberFormatException nfe){
                        System.out.println("Arguments parse fail : first argument after -l (--lines) arg is not an integer.");
                        System.exit(1);
                    }
                } else {
                    System.out.println("Arguments parse fail : no arguments after -l (--lines).");
                    System.exit(1);
                }
            }
            ////numeric suffixes///////////////////////////////////////////////////////////////////////////////
            if (args[i].equalsIgnoreCase("-d") | args[i].equalsIgnoreCase("--numericprefixes")) {
                arg_numeric = true;
            }
            ////filename///////////////////////////////////////////////////////////////////////////////////////
            if (!args[i].startsWith("-") & args[i].endsWith(".txt")){
                filename = args[i];
            }
            ////prefix/////////////////////////////////////////////////////////////////////////////////////////
            if (!args[i].startsWith("-") & !args[i].endsWith(".txt") & !args[i].equals("" + num)){
                prefix = args[i];
            }
            ///////////////////////////////////////////////////////////////////////////////////////////////////
        }

        if (!arg_numeric & prefix.isEmpty()){
            System.out.println("Prefix not specified, using \"x\".");
            prefix = "x";
        }

        if (arg_bytes & arg_lines){
            System.out.print("Specified both -l and -b. Using only -l by default.");
            arg_bytes = false;
        }

        if (filename.isEmpty()){
            System.out.println("Filename not specified, using default.txt instead.");
            filename = "default.txt";
        }

        file = readFile(filename);

        if (file.isEmpty()){
            System.out.print("File is empty.");
            System.exit(1);
        }

        if(arg_bytes | arg_lines){
            if(num > 0){
                if (!arg_numeric){
                    newfilename = prefix + "aa";
                } else { newfilename = prefix + "0"; }
                if(arg_bytes){
                    byte[] bytes_arr = file.getBytes(StandardCharsets.UTF_8);
                    for (int i = 0; i < bytes_arr.length; i++){
                        try{
                            FileWriter fstream = new FileWriter(newfilename + ".txt",true);
                            BufferedWriter out = new BufferedWriter(fstream);
                            out.write(bytes_arr[i]);
                            out.close();
                        }catch (Exception e){
                            System.err.println("Error while writing to file: " +
                                    e.getMessage());
                        }
                        if (i % num == 0){
                            newfilename = getNextPrefix(prefix, newfilename, arg_numeric);
                        }
                    }
                } else {
                    String[] file_arr = file.split("\n");
                    for (int i = 0; i < file_arr.length; i++){
                        try{
                            FileWriter fstream = new FileWriter(newfilename + ".txt",true);
                            BufferedWriter out = new BufferedWriter(fstream);
                            out.write(file_arr[i]);
                            out.close();
                        }catch (Exception e){
                            System.err.println("Error while writing to file: " +
                                    e.getMessage());
                        }
                        if (i % num == 0){
                            newfilename = getNextPrefix(prefix, newfilename, arg_numeric);
                        }
                    }
                }
            } else {
                System.out.println("Arguments parse fail : received -l (--lines) or -b (--bytes) with negative amount.");
                System.exit(1);
            }
        }

    }
    public static String getNextPrefix(String prefix, String previous, boolean arg_numeric){
        String result;
        String old_prefix = previous.substring(prefix.length());
        int buff_int;

        if(!arg_numeric){
            if (old_prefix.charAt(1) < 'z'){
                buff_int = old_prefix.charAt(1);
                buff_int ++;
                result = prefix + old_prefix.charAt(0) + (char)buff_int;
            } else if (old_prefix.charAt(0) < 'z'){
                buff_int = old_prefix.charAt(0);
                buff_int ++;
                result = prefix + (char)buff_int + "a";
            } else {
                result = prefix + "aa";
            }///////////////////////////////////////
        }   else { //numeric prefix
            buff_int = Integer.parseInt(old_prefix);
            buff_int++;
            result = prefix + buff_int;
        }
        return result;
    }
    public static String readFile(String filename) throws IOException {
        String file = "";
        try {
            file = Files.readString(Paths.get(filename), StandardCharsets.UTF_8);
            System.out.println("\nFile contents : \n" + file);
        } catch (NoSuchFileException nsfe){
            System.out.println("File opening fail : No such file " + filename);
            System.exit(1);
        }
        return file;
    }
}