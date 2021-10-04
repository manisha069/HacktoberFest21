#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        long long int l,r;
        cin>>l>>r;
        int x=(r-l)%4;
        if(l%2!=0)
        {
            if(x==0||x==1)
                cout<<"Odd\n";
            else
                cout<<"Even\n";
        }
        else
        {
            if(x==2||x==1)
                cout<<"Odd\n";
            else
                cout<<"Even\n";
        }
    }
}
