import java.time.LocalDateTime;
import java.util.Random;
public class Main {
    public static void main(String[] args) {
        Person person = new Person();
        ElectronicClock elClock = new ElectronicClock();
        person.MeasureTime(elClock);

        AnalogClock anClock = new AnalogClock();
        person.MeasureTime(anClock);

        Clock anClock_adapter = new Adapter(anClock);   //anClock --> anClock_adapter
        person.MeasureTime(anClock_adapter);
    }
}
interface Clock {
    void MeasureTime();
}
class ElectronicClock implements Clock{
    private Random rand = new Random();
    private LocalDateTime Time = LocalDateTime.of(
            2022, 11, 17,    //YMD
                rand.nextInt(0, 12),    //Hours
                rand.nextInt(0, 60),    //Minutes
                rand.nextInt(0, 60)     //Seconds
    );
    public void MeasureTime() {
        System.out.println("Время: "+Time);
    }
}

class AnalogClock implements Clock{
    private int AngleH;
    private int AngleM;
    private int AngleS;
    public AnalogClock() {
        Random rand = new Random();
        AngleH = rand.nextInt(0, 361);
        AngleM = rand.nextInt(0, 361);
        AngleS = rand.nextInt(0, 361);
    }
    public int GetAngleHours() {
        return AngleH;
    }
    public int GetAngleMinutes() {
        return AngleM;
    }
    public int GetAngleSeconds() {
        return AngleS;
    }
    public void MeasureTime() {
        System.out.println("Угол поворота стрелки часов: "+GetAngleHours());
        System.out.println("Угол поворота стрелки минут: "+GetAngleMinutes());
        System.out.println("Угол поворота стрелки Секунд: "+GetAngleSeconds());
    }
}

class Adapter extends ElectronicClock{
    AnalogClock mechanicalClock;
    public Adapter(AnalogClock clock) {
        mechanicalClock = clock;
    }
    public void MeasureTime() {
        int hour = mechanicalClock.GetAngleHours() / 30;
        int minute = mechanicalClock.GetAngleMinutes() / 6;
        int seconds = mechanicalClock.GetAngleSeconds() / 6;
        LocalDateTime datetime = LocalDateTime.of(2022, 11, 17, hour, minute, seconds);
        System.out.println("Время: "+datetime);
    }
}

class Person
{
    public void MeasureTime(Clock clock)
    {
        clock.MeasureTime();
    }
}