//Author : Sundar

#include<iostream>
using namespace std;


int power_iterative(int a,int b)
{
	//binary exponentation

	int res=1;
	/* eg 3^11 =3^1011 do square 3's then if bit is set
	multiply it with res or else skip*/
	while(b>0)
	{
		if(b&1) //b%2==1
			res*=a;
		a*=a;
		b=b>>1; //b/=2;
	}
	return res;
}

int power_recursive(int n,int a)
{
    if(a==0) return 1;
    int subprob= power_recursive(n,a/2);

    if(a&1)
    {
        return n*subprob*subprob;
    }
    else return subprob*subprob;
    
}


int main()
{
    int n,m;
    cin>>n>>m;

    cout<<"Calculating N^M using RECURSION : "<<power_recursive(n,m)<<endl;
    
    cout<<"Calculating N^M using ITERATION : "<<power_iterative(n,m)<<endl;
    return 0;
}
