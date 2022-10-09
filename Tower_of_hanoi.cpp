#include<bits/stdc++.h>
using namespace std;

string tower(int n,char s,char a,char d)
{
    if(n==1)
    {
        cout<<" "<<s<<" "<<d<<endl;
        return " ";
    }
    tower(n-1,s,d,a);
    cout<<" "<<s<<" "<<d<<endl;
    tower(n-1,a,s,d);
}

int main()
{
    	int n;
	
	cout<<"Enter no. of disks:";	
	cin>>n;
	//calling the TOH 
	tower(n,'A','B','C');
	
	return 0;


return 0;
}
