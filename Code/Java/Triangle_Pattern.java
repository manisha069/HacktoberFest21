import java.util.Scanner;

public class Triangle_Pattern {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number - ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {

            // inner loop to handle number of columns
            for (int j = 0; j <= i; j++) {
                // printing stars
                System.out.print("* ");
            }

            // just to break line, after loop for each row is completed
            System.out.println();
        }
    }
}
