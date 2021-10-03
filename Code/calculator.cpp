#include <bits/stdc++.h>
using namespace std;
class calculator
{
    int num;
    public:
    calculator(int i=0) : num(i){}
    
    calculator operator + (calculator const &obj1)
    {
        calculator res;
        res=num+obj1.num;
        return res;
    }
    friend calculator operator * (calculator const &obj1,calculator const &obj2)//concatenation of two RSA using operator overloading
    {
        calculator res;
        res=obj1.num*obj2.num;
        return res;
    }
    void display()
    {
        cout<<num<<endl;
    }
};
int main()
{
    calculator a(90),b(45),e(10),f(20);
    calculator c,d;
    c=a+b;
    c.display();
    d=12*e;
    d.display();
}