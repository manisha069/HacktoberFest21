/*
 * 
 * Title: Ceasar Cipher Encoder
 * 
 */

import java.util.*;

class Ceasar_Cipher {
    public static String encode(int k, String s) {
        String result="";
        if(k>25) {
            System.out.println("\nShift value should be less or equal to than 25... Try Again");
            return result;
        }
        int len=s.length();
        if(len==0) {
            System.out.println("\nNo string entered... Try Again");
            return result;
        }
        String enc_lower="abcdefghijklmnopqrstuvwxyz";
        String enc_upper="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(int i=0;i<len;i++) {
            if(s.charAt(i)>=65 && s.charAt(i)<=90) {
                int temp = enc_upper.indexOf(s.charAt(i));
                temp=((temp+k)%26);
                result=result+(enc_upper.charAt(temp));
            }
            else if(s.charAt(i)>=97 && s.charAt(i)<=122) {
                int temp = enc_lower.indexOf(s.charAt(i));
                temp=((temp+k)%26);
                result=result+(enc_lower.charAt(temp));
            }
            else {
                result=result+(s.charAt(i));
            }
        }
        return result;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the string to be encoded: ");
        String str = sc.nextLine();
        System.out.println("Enter the shift constant: ");
        int k=sc.nextInt();
        String result=encode(k, str);
        System.out.println("Entered String: "+str);
        System.out.println("Encoded String: "+result);
    }
}

// This code was implemented on day 51 of 100 days of code //
