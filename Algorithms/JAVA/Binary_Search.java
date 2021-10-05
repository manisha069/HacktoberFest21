
import java.util.*;
import java.io.IOException;

class Binary_Search{

    static int binarySearch(int arr[], int start, int end, int key){
        
        if(end>=start)
        {
            int mid= start + (end-start)/2;

            if(arr[mid]==key)
                return mid;

            else if(key<arr[mid])
                return binarySearch(arr, start, mid-1, key);

            return binarySearch(arr, mid+1, end, key);
        }
        return -1;
    }

    public static void main(String[] args)throws IOException{
    Scanner sc=new Scanner(System.in);
    int n = sc.nextInt();
    int key=sc.nextInt();
    int[] arr=new int[n];
    for(int i=0;i<n;i++)
        arr[i]=sc.nextInt();
    int ans=binarySearch(arr, 0, n-1, key);
    if(ans==-1)
        System.out.println("Element is not present in the Array");
    else    
        System.out.println("Element is present at index "+ans);
    sc.close();
    }
}