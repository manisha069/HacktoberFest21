#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


void HeapMin(int a[], int cont){
    for(int i = cont/2; i >= 1; i--){
        int k = i;
        int v;
        v = a[k];

        bool heap = false;
        while(!heap && 2*k <= cont){
            int j = 2*k;
            if(j<cont){
                if(a[j] < a[j+1]) j = j+1;
                
            }
            if(v >= a[j]){
                heap = true;
            }
            else{
                a[k] = a[j];
                k = j;
            }
        }
        
        a[k] = v;
        cout << "Heapify no " << v << endl;
        for(int j = 1; j <= 12; j++){
            cout << a[j] << " ";
        }
        cout << endl;
        
    }
}



int main(){
    int array[] = {-1, 18, 20, 2, 19, 15, 11, 6, 21, 14, 40, 0, 27};
    int size;
    size = 12;
    
    HeapMin(array, size);
}
