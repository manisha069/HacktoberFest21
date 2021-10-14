## Implemention of Dynamic-array in C++ 


#include<iostream>
using namespace std;

int main(){
 
 int *p, n;
 p=(int*)malloc(n*sizeof(int));
 
 printf("Enter elements in array: ";
 for(int i=0 ;i < n; i++){
   cin("%d", (p+i));
 }
 
 printf("\n The elements are:" \n);
  for(int i=0 ;i < n; i++){
   cout("%d \n ", (p+i));
 }
 
  return 0;
