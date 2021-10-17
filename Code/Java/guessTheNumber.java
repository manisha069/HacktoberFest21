import java.util.Random;
import java.util.Scanner;

class game{
   private int rand;
   private int n;
   private  int i=0;
   private int count=0;
    public void RandomNumberGenerator(){
        Random number = new Random();
        rand = number.nextInt(100) + 1;
    }
    public int TakeUserInput(){
      Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number you want to guess :- ");
         n = sc.nextInt();
        return n;
    }
    public void GetGuesses(){
        System.out.println("Total no of Guesses are :- "+count);
    }
    public void IsNumberCorrect(){

        while(i<=4){
            if (rand == n) {
                System.out.println("Congrts You have Guessed the Correct Number");
                break;
            } else if (rand < n) {
                System.out.println("You have Choosen a greater number try again");
                TakeUserInput();
            } else {
                System.out.println("You have Chossed a lesser number try again");
                TakeUserInput();
            }
            count++;
            i++;
        }
    }
}
public class guessTheNumber {
    public static void main(String[] args) {

        //        Ignore This it's Just a Header

        System.out.println("======================================");
        System.out.println("   WELCOME TO GUESS THE NUMBER GAME   ");
        System.out.println("======================================");


         game test = new game();
            test.TakeUserInput();
            test.RandomNumberGenerator();
            test.IsNumberCorrect();
            test.GetGuesses();

        //            Ignore This it's Just a Footer

        System.out.println("===================================");
        System.out.println("  This Game is Created by Dibendu  ");
        System.out.println("===================================");
    }
}