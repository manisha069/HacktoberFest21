#include<bits/stdc++.h>
using namespace std;
int LCM(int,int);

int main()
{
    int first,second;
    cin>>first>>second;

    cout<<LCM(first,second);
    return 0;
}

int LCM(int first,int second)
{
    int lcm;

    if(first>second)
    {
        lcm=first;
    }

    else
    {
        lcm=second;
    }

    while(true)
    {
        if(lcm%first==0 && lcm%second==0)
        {
            return lcm;
        }

        lcm++;
    }
    return 0;
}
