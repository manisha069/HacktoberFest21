// Armstrong number in java using recursion
import java.util.Scanner;
class arm
{
   int n, s;
   arm(int num1)
   {
      n = num1;
      s = 0;
   }
   long powerOf(int a, int b)
   {
      if(b == 0)
      {
         return 1;
      }
      else
      {
         return a * powerOf(a, b - 1);
      }
   }
   void executePowerOf()
   {
      int d = n, r;
      long t = (long)s;
      while(d > 0)
      {
         r = d % 10;
         d = d / 10;
         t = t + powerOf(r, 3);
      }
      if(n == t)
      {
         System.out.println(n+" is an Armstrong number.");
      }
      else
      {
         System.out.println(n+" is not an Armstrong number.");
      }
   }
   public static void main(String[] args) 
   {
      Scanner sc = new Scanner(System.in);
      System.out.println("Please enter the number: ");
      int n = sc.nextInt();
      arm obj = new arm(n);
      obj.executePowerOf();
      sc.close();
   }
}
