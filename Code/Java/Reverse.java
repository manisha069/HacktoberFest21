

import java.util.Scanner;

public class Reverse {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int rev, ans=0;

        System.out.println("Enter a number");
        int n = in.nextInt();

        while (n>0)
        {
            rev = n%10;
            n = n/10;
            ans = ans * 10 + rev;
        }

        System.out.println("Reversed number is " + ans);


    }
}
