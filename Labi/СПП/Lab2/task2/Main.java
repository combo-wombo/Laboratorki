import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.NoSuchFileException;
import java.nio.file.Paths;

public class Main{
    public static void main(String[] args) throws IOException {

        boolean arg_bytes, arg_lines, arg_numeric;
        String filename, prefix, file;
        int num;

        arg_bytes = arg_lines = arg_numeric = false;
        num = 0;
        filename = prefix = file = "";

        if (args.length == 0){
            System.out.println("Arguments parse fail : no arguments (use --help to learn about usable parameters).");
            System.exit(1);
        }

        for (int i = 0; i<args.length; i++){
            ////help///////////////////////////////////////////////////////////////////////////////////////////
            if (args[i].equalsIgnoreCase("-h") | args[i].equalsIgnoreCase("--help")){
                System.out.println("Usage : lab2 [-b OR -l <num>] [-d] [<filename.txt> [prefix]]");
                System.out.println("\nParameters : ");
                System.out.println("\t-b (--bytes) - divide the original file into multiple files that consist of <num> bytes from the original file.");
                System.out.println("\t-l (--lines) - split the file into multiple files that contain a specified amount of lines from the original.");
                System.out.println("\t-d (--numericprefixes) - the files will use a numeric prefix (00_ex.txt, 01_ex.txt, 02_ex.txt and so on).");
                System.out.println("\nExample : lab2 -b 60 file1.txt -d");
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
                // do work
            } else {
                System.out.println("Arguments parse fail : received -l (--lines) or -b (--bytes) with negative amount.");
                System.exit(1);
            }
        }
        
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