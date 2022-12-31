public class Main {
    public static void main(String[] args) {
        // Клиентский код выбирает конкретную стратегию и передаёт её в
        // контекст. Клиент должен знать о различиях между стратегиями,
        // чтобы сделать правильный выбор.
        var context = new Context();

        System.out.println("Client: Strategy is VowelRemoval");
        context.SetStrategy(new VowelRemoval());
        context.DoSomeBusinessLogic();

        System.out.println();

        System.out.println("Client: Strategy is Shift");
        context.SetStrategy(new Shift());
        context.DoSomeBusinessLogic();

        System.out.println();

        System.out.println("Client: Strategy is reverseWithXOR");
        context.SetStrategy(new reverseWithXOR());
        context.DoSomeBusinessLogic();
    }
}

class Context {
    // Контекст хранит ссылку на один из объектов Стратегии. Контекст не
    // знает конкретного класса стратегии. Он должен работать со всеми
    // стратегиями через интерфейс Стратегии.
    private IStrategy _strategy;
    public Context()
    { }
    // Обычно Контекст принимает стратегию через конструктор, а также
    // предоставляет сеттер для её изменения во время выполнения.
    public Context(IStrategy strategy)
    {
        this._strategy = strategy;
    }
    // Обычно Контекст позволяет заменить объект Стратегии во время
    // выполнения.
    public void SetStrategy(IStrategy strategy)
    {
        this._strategy = strategy;
    }
    // Вместо того, чтобы самостоятельно реализовывать множественные версии
    // алгоритма, Контекст делегирует некоторую работу объекту Стратегии.
    public void DoSomeBusinessLogic()
    {
        String str = "My string 1 (ONE)...";
        //System.out.println(str);
        var result = _strategy.DoAlgorithm(str);
        System.out.println(result);
    }
}

// Интерфейс Стратегии объявляет операции, общие для всех поддерживаемых
// версий некоторого алгоритма.
//
// Контекст использует этот интерфейс для вызова алгоритма, определённого
// Конкретными Стратегиями.
interface IStrategy {
    String DoAlgorithm(String data);
}

// Конкретные Стратегии реализуют алгоритм, следуя базовому интерфейсу
// Стратегии. Этот интерфейс делает их взаимозаменяемыми в Контексте.
class VowelRemoval implements IStrategy { //Удаление гласных
    public String DoAlgorithm(String date){
            String res = date;
            String[] temp = { "e", "y", "u", "i", "o", "a", "E", "Y", "U", "I", "O", "A", };
            for (String s : temp) {
                res = res.replace(s, "");
            }
            return res;
    }
}

class Shift implements IStrategy {// Сдвиг
    public String DoAlgorithm(String date){
        String res = date;
        String[] alphabet = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
        String[] ALPHABET = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
        int shift = 10;

        for(int i = 0; i < alphabet.length; i++){
            int temp = i + shift;
            if(temp >= alphabet.length){
                temp = temp - alphabet.length;
            }
            res = res.replace(alphabet[i], alphabet[temp]);
        }

        for (int i = 0; i < ALPHABET.length; i++){
            int temp = i + shift;
            if (temp >= ALPHABET.length){
                temp = temp - ALPHABET.length;
            }
            res = res.replace(ALPHABET[i], ALPHABET[temp]);
        }
        return res;
    }
}

class reverseWithXOR implements IStrategy {// применение операции исключающее
    public String DoAlgorithm(String date) {
        char[] array = date.toCharArray();
        int length = array.length;
        double val = array.length / 2.0;
        int half = (int)Math.floor(val);

        for (int i = 0; i < half; i++) {
            array[i] ^= array[length - i - 1];
            array[length - i - 1] ^= array[i];
            array[i] ^= array[length - i - 1];
        }
        return new String(array);
    }
}
















