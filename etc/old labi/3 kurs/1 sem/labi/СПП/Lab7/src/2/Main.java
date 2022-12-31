import java.awt.*;
import java.util.Scanner;
import javax.swing.*;
import java.util.Random;

class Main extends JFrame {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter angle by x (1-10) : Pi/");
        double n = sc.nextInt();
        System.out.print("Enter angle by y (1-10) : Pi/");
        double m = sc.nextInt();
        System.out.print("Enter recursion depth : "); // чем больше коэф. тем меньше шагов рекурсии
        int depth = sc.nextInt();

        JFrame window = new JFrame("Pythagoras tree");
        window.setSize(620, 600);
        window.setBackground(Color.BLACK);
        window.setContentPane(new PythagorasTree(n, m, depth));
        window.setResizable(false);
        window.setDefaultCloseOperation(EXIT_ON_CLOSE);
        window.setVisible(true);
    }
}

class PythagorasTree extends JPanel {
    private double __n;
    private double __m;
    private int __depth;

    PythagorasTree(double n, double m, int depth) {
        __n = n;
        __m = m;
        __depth = depth;
    }

    public void setColor(Graphics g){
        Random rand = new Random();
        int randNum = rand.nextInt(5);
        if(randNum == 0){
            g.setColor(Color.RED);
        }
        else if(randNum == 1){
            g.setColor(Color.MAGENTA);
        }
        else if(randNum == 2){
            g.setColor(Color.GREEN);
        }
        else if(randNum == 3){
            g.setColor(Color.BLUE);
        }
        else {
            g.setColor(Color.YELLOW);
        }
    }

    public void paintComponent(Graphics g){
        super.paintComponents(g);
        drawTree(320, 460, 200, Math.PI/2, g);
    }

    private void drawTree(double x, double y, double L, double a, Graphics g) {
        setColor(g);
        if(L > __depth) {
            L = L * 0.7;
            double x1 = x + L * Math.cos(a);
            double y1 = y - L * Math.sin(a);
            g.drawLine((int)x, (int)y, (int) (x1), (int) (y1));
            x = x1;
            y = y1;

            drawTree(x, y, L, a + Math.PI / __n, g);
            drawTree(x, y, L, a - Math.PI / __m, g);
        }
    }

}