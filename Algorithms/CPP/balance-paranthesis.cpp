#include<bits/stdc++.h>
using namespace std;
int main()
{
string str="[{()]]";
stack<char> st;

for(int i=0; i<str.length(); i++)
{

    if(str[i]=='{' || str[i]=='(' ||str[i]=='[')
        st.push(str[i]);
    
      else if(!st.empty() && str[i]==')')
    {
        if(!st.empty()&& st.top()=='(')
        st.pop();
        else
        break;
    }

    else if(!st.empty() && str[i]==']')
    {
        if(!st.empty()&& st.top()=='[')
        st.pop();
    else
        break;
    }
     else if(!st.empty() && str[i]=='}')
    {
        if(!st.empty()&& st.top()=='{')
        st.pop();
    
    else
        break;
    }
}
if(!st.empty())
{
    cout<<"wrong"<<" ";
}
else
cout<<"true"<<" ";
return 0;
}
