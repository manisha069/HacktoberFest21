// Jump Search

#include<iostream>
#include<cmath>

using namespace std;
int jump_Search(int a[], int n, int item) {
   int i = 0;
   int m = sqrt(n); 

   while(a[m] <= item && m < n) {  
      i = m;  
      m += sqrt(n);
      if(m > n - 1)  
         return -1; 
   }

   for(int x = i; x<m; x++) { 
      if(a[x] == item)
         return x; 
   }
   return -1;
}

int main() {
   int n, item, loc;
   cout << "\n Enter number of items: ";
   cin >> n;
   int arr[n]; 
   cout << "\n Enter items: ";

   for(int i = 0; i< n; i++) {
      cin >> arr[i];
   }

   cout << "\n Enter search key to be found in the array: ";
   cin >> item;
   loc = jump_Search(arr, n, item);
   if(loc>=0)
      cout << "\n Item found at location: " << loc;
   else
      cout << "\n Item is not found in the list.";
}