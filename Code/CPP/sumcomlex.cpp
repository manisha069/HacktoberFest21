#include<iostream>
using namespace std;

class complex
{
    int a,b;
    public:
    void setdata(int x, int y)
    {
        a=x;
        b=y;
    } 

    void sumdata(complex o1, complex o2)
    {
        a= o1.a+o2.a;
        b= o1.b+o2.b;
    }

    void printdata()
    {
        cout<<"sum of complex number is "<<a<<" + "<<b<<"i"<<endl;
    }

};

int main()
{
    complex c1,c2,c3;
    int x,y,g,f;

    cout<<"enter the real part of 1st complex number";
    cin>>x;
    cout<<"enter the imaginary part of 1st complex number";
    cin>>y;
    c1.setdata(x,y);

    cout<<"enter the real part of 2nd complex number";
    cin>>g;
    cout<<"enter the imaginary part of 2nd complex number";
    cin>>f;
    c2.setdata(g,f);

    c3.sumdata(c1,c2);
    c3.printdata();

    return 0;
}