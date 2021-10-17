import java.io.IOException;
import java.util.Scanner;

public class Kadanes_algorithm {
    
    static int maxsum(int arr[],int n)
    {
        int max=Integer.MIN_VALUE; //Maximum sub-array sum
        int currentSum=arr[0];

        for(int a : arr)
        {
            currentSum+=a;
            if(currentSum>max)
                max=currentSum;
            if(currentSum<0)
                currentSum=0;
        }
        return max; 
    }
    public static void main(String[] args) throws IOException 
    {
        Scanner sc=new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr=new int[n];
        for (int i = 0; i < n; i++) 
            arr[i]=sc.nextInt();
        
        System.out.println("Maximum sub Array sum is: "+maxsum(arr,n));
        sc.close();
    }
}
