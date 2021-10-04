#include <algorithm> 
#include<iostream>
#include<string>
using namespace std; 
int main() 
{ 
    string str = "Journal Dev reverse example"; 
    reverse(str.begin(), str.end()); 
    cout<<"\n"<<str; 
    return 0;
}
