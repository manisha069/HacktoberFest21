/* Developed by Aditya More (Adi Star Coders) Copyright 2021*/

package com.adistarcoders;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner no = new Scanner(System.in);

        long num;
        String num2 = null;
        int ch = 0,ch2=0;
        System.out.println("\n1.Decimal \n2.Binary \n3.Octal \n4.HexaDecimal");
        System.out.println("\nchoose your number system : ");
        ch=no.nextInt();
        switch(ch)
        {
            case 1: // it's decimal number
                System.out.println("\nEnter your Decimal number :");
                num = no.nextLong();
                System.out.println("\n1.Binary \n2.Octal \n3.HexaDecimal \n4.All of the above");
                System.out.println("\nchoose your number system : ");
                ch2=no.nextInt();
                if(ch2==1){
                   num2 = Long.toBinaryString(num);
                    System.out.println("Binary number is : " + num2);
                }
                if(ch2==2){

                    System.out.println("Octal number is "+Long.toOctalString(num));
                }
                 if(ch2==3){
                     System.out.println("HexaDecimal number is "+Long.toHexString(num));
                 }
                 if(ch2==4){
                     num2 = Long.toBinaryString(Math.toIntExact(num));
                     System.out.println("Binary number : " + num2);
                     System.out.println("Octal number : "+Long.toOctalString(num));
                     System.out.println("HexaDecimal number : "+Long.toHexString(num));
                 }

                break;

                 case 2:
                System.out.println("\nEnter your Binary number :");
                num = no.nextLong();
                System.out.println("\n1.Decimal \n2.Octal \n3.HexaDecimal \n4.All of the above");
                System.out.println("\nchoose your number system : ");
                ch2=no.nextInt();
                if(ch2==1){

                    System.out.println("Decimal number is "+Long.parseLong(String.valueOf(num),2));
                }
                if(ch2==2){
                    num=Long.parseLong(String.valueOf(num),2);
                    System.out.println("Octal number : "+Long.toOctalString(num));
                }
                if(ch2==3){

                    String hexa = Long.toHexString(num);
                    System.out.println("HexaDecimal Value is : " + hexa);
                }
                if(ch2==4){
                    System.out.println("Decimal number : "+Long.parseLong(String.valueOf(num),2));
                    num=Long.parseLong(String.valueOf(num),2);
                    System.out.println("Octal number : "+Long.toOctalString(num));
                    String hexa = Long.toHexString(num);
                    System.out.println("HexaDecimal number: " + hexa);

                }

                break;

            case 3: System.out.println("\nEnter your Octal number :");
         num = no.nextLong();
                System.out.println("\n1.Decimal \n2.Binary \n3.HexaDecimal \n4.All of the above");
                System.out.println("\nchoose your number system : ");
                ch2=no.nextInt();
                if(ch2==1){

                    System.out.println ("Decimal number is "+Long.parseLong(String.valueOf(num),8));

                }
                if(ch2==2){

                    System.out.println("Binary number : " +Long.toBinaryString(Long.parseLong(String.valueOf(num),8))) ;
                }
                if(ch2==3){
                    num = Long.parseLong(String.valueOf(num), 8);
                    System.out.println("HexaDecimal number: "+Long.toHexString(num));
                }
                if(ch2==4){
                    System.out.println ("Decimal number is "+Long.parseLong(String.valueOf(num),8));
                    System.out.println("Binary number : " +Long.toBinaryString(Long.parseLong(String.valueOf(num),8))) ;
                    num = Long.parseLong(String.valueOf(num), 8);
                    System.out.println("HexaDecimal number : "+Long.toHexString(num));
                }
                break;

            case 4 : System.out.println("\nEnter your HexaDecimal number :");
                num2 =no.next();
                System.out.println("\n1.Decimal \n2.Binary \n3. Octal \n4.All of the above");
                System.out.println("\nchoose your number system : ");
                ch2=no.nextInt();
                if(ch2==1){

                    System.out.println ("Decimal number is "+Long.parseLong(num2,16));

                }
                if(ch2==2){

                    System.out.println("Binary number is " +Long.toBinaryString(Long.parseLong(num2,16))) ;
                }
                if(ch2==3){




                    System.out.println("Octal number: "+Long.toOctalString(Long.parseLong(num2,16)));
                }
                if(ch2==4){
                    System.out.println ("Decimal number is "+Long.parseLong(num2,16));
                    System.out.println("Binary number is " +Long.toBinaryString(Long.parseLong(num2,16))) ;

                    System.out.println("Octal number: "+Long.toOctalString(Long.parseLong(num2,16)));

                }
                break;


            default:
                throw new IllegalStateException("Unexpected value: " + ch);
        }



    }
}
