#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n=0;
    cin>>n;
    int sum=0;
    int original=n;
    while(n>0){
        int lastdigit=n%10;
        sum += round(pow(lastdigit,3));
        n = n/10;
    }

    if(sum==original){
        cout<<"Armstrong Number\n";
    }
    else{
        cout<<"Not armstrong\n";
    }
}
