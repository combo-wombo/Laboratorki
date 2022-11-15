import java.util.Scanner;
public class Main{
    public static void main(String[] args)
    {
        int n;
        Scanner sc=new Scanner(System.in);
        System.out.print("Matrix size (N): ");
        n=sc.nextInt();

        double[][] matrix = new double[n][n];
        System.out.println("Enter elements: ");
        for (int i = 0; i<n; i++){
            System.out.println("Row " + (i+1) + " ");
            for (int j = 0; j < n; j++){
                matrix[i][j] = sc.nextDouble();
            }
        }

        PrintMatrix(matrix);
        transpose(matrix);
        PrintMatrix(matrix);
    }
    public static void PrintMatrix(double[][] matrix){
        System.out.println("\nMatrix: ");
        for (int i = 0; i<matrix.length; i++){
            for (int j = 0; j < matrix.length; j++){
                System.out.print(matrix[i][j] + " ");
            }
            System.out.print("\n");
        }
    }

    public static double[][] transpose(double[][] matrix){
        System.out.println("Transpose used.");
        double buff = 0;
        for (int i = 0; i < matrix.length; i++){
            for (int j = i; j < matrix.length; j++){

                buff = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = buff;
            }
        }
        return matrix;
    }
}