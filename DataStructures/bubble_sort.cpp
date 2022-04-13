#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <string.h>
using namespace std;
#define ll long long int
#define rep(a, b, c) for (ll a = b; a < c; a++)

void bubblesort(int a[], int n)//O(n^2)
{int r=0;
    int i,j;
    rep(i,0,n){
        r++;
        rep(j,0,n-i-1){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }cout<<r<<endl;
}

void optimised_bubblesort(int a[], int n)//O(nlog(n))
{int r=0;
    int i,j;
    rep(i,0,n){
        r++;
        bool flag=false;
        rep(j,0,n-i-1){
            if(a[j]>a[j+1]){
                flag=true;
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        if(flag==false){
            break;
        }
    }cout<<r<<endl;
}




int main()
{
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    bubblesort(a, n);
    //optimised_bubblesort(a,n);
    rep(i, 0, n)
    {
        cout << a[i] << " ";
    }
  
    return 0;
}
