void moveElements(int arr[], int n){ 
   int key,j;
   for (int i = 0; i < n; i++)
   {
       key = arr[i];
       j = i-1;
       while (j>=0 && arr[j]<0 && key>=0)
       {
           arr[j+1] = arr[j];
           j--;
       }
       arr[j+1] = key;
   }
}
