// It sorts the array of 0's 1's and 2's



#include <iostream>

using namespace std;

void dnf_sort(int a[], int n)
{
    // sort arrays of 0's, 1's and 2's 
    
    int lo = 0;
    int hi = n-1;
    int mid = 0;
    
    while(mid <= hi)
    {
        if(a[mid] == 0)
        {
            
            swap(a[mid], a[lo]);
            lo++;
            mid++;
            
        }
        
        if(a[mid] == 1)
        {
            // you just go to next position
            mid++;
            
        }
        
        if(a[mid] == 2)
        {
            
            swap(a[mid], a[hi]);
            hi--;
            
        }
        
        
    }
    
    return;
    
}


int main()
{
    // Please take inputs in form of 0's 1's and 2's
    
    int n;
    cin >> n;
    int a[n]; // {2,1,1,1,1,0,1,1,1,0,0,2,0};
    
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    dnf_sort(a, n);
    
    for(int i = 0; i < n; i++)
    {
        
        cout << a[i] << "  ";
    }

    return 0;
}


/*

OUTPUT
13
2 1 1 1 1 0 1 1 1 0 0 2 0
0  0  0  0  1  1  1  1  1  1  1  2  2 

*/
