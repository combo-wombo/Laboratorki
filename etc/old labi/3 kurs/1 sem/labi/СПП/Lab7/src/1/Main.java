import java.awt.*;
import java.util.Scanner;
import javax.swing.*;

class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter width : ");
        int windowX = sc.nextInt();
        System.out.print("Enter height : ");
        int windowY = sc.nextInt();
        System.out.print("Enter diameter : ");
        int diameter = sc.nextInt();
        System.out.print("Enter X pos : ");
        int posX = sc.nextInt();
        System.out.print("Enter Y pos : ");
        int posY = sc.nextInt();
        System.out.print("Speed : ");
        int speed = sc.nextInt();
        sc.close();

        Circle app = new Circle(windowX, windowY, diameter, posX, posY, speed);
        app.run();
    }
}

class Circle extends JFrame {
    private int __x;
    private int __y;
    private final int __windowX;
    private final int __windowY;
    private final int __diameter;
    private final int __speed;
    private boolean __moveLeft;
    private boolean __moveDown;

    public Circle(int windowX, int windowY, int diameter, int posX, int posY, int speed) {
        super("circle");
        setSize(windowX, windowY);
        setVisible(true);
        setResizable(false);

        __diameter = diameter;
        __windowX = windowX;
        __windowY = windowY;
        __x = posX;
        __y = posY;
        __moveDown = false;
        __speed = speed;
    }

    public void paint(Graphics g) {
        g.fillRect(0, 0, __windowX, __windowY);
        g.setColor(Color.RED);
        g.drawOval(__x, __y, __diameter, __diameter);
    }

    public void run(){
        while(true){
            if(__x >= __windowX - __diameter){
                __moveDown = true;
            }
            if(__x <= 0){
                __moveDown = false;
            }

            if(__y >= __windowY - __diameter){
                __moveLeft = true;
            }
            if(__y <= 0){
                __moveLeft = false;
            }

            if (__moveDown) {
                __x -= __speed;
            } else {
                __x += __speed;
            }
            if (__moveLeft) {
                __y -= __speed;
            } else {
                __y += __speed;
            }
            repaint();

            try{
                Thread.sleep(5);
            }
            catch(InterruptedException e){
            }
            setDefaultCloseOperation(EXIT_ON_CLOSE);
        }
    }
}
