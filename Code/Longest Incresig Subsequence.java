import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        
        Scanner scn=new Scanner(System.in); //taking input
        int n=scn.nextInt();
        int []arr=new int[n];
        for(int i=0;i<arr.length;i++)
        {
            arr[i]=scn.nextInt();
        }
        
        int []dp=new int[n]; // make an array of size n
        dp[0]=1;
        int omax=1; // final answer
        for(int i=0;i<dp.length;i++)
        {
            int max=0;
            for(int j=0;j<i;j++)
            {
                if(arr[j]<arr[i])
                {
                    max=Math.max(max,dp[j]);
                }
            }
            dp[i]=max+1;
            omax=Math.max(omax,dp[i]);
        }
        System.out.println(omax);
    }

}
