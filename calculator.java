
public class calculator {

    int add(int a, int b) {
        return a + b;
    }

    int subtract(int a, int b) {
        return a - b;
    }

    int multiply(int a, int b) {
        return a * b;
    }

    int divide(int a, int b) {
        if (b == 0) {
            System.out.println("Error: Division by zero");
            return 0; // or throw an exception
        }
        return a / b;
    }

    public static void main(String[] args) {

        //ekta notun jinish create korlam

        calculator calc = new calculator();
        System.out.println("jog: " + calc.add(5, 3));
        System.out.println("bijog: " + calc.subtract(5, 3));
        System.out.println("Multiplication: " + calc.multiply(5, 3));
        System.out.println("Division: " + calc.divide(5, 3));
    }
}
