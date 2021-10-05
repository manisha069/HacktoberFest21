package Operators;

public class InfiniteLoop {
    public static void main(String... input) {
        for (int i = 0; i < 4; i = i++ ) {
            System.out.println("Hi");
        }
    }
}
