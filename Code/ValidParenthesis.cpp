#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(!st.empty()&&s[i]==')'&&st.top()=='(')
                st.pop();
            else if(!st.empty()&&s[i]=='}'&&st.top()=='{')
                st.pop();
            else if(!st.empty()&&s[i]==']'&&st.top()=='[')
                st.pop();
            else 
                st.push(s[i]);
        }
        return(st.empty());

int main(){
    string s;
    cin>>s;
    cout<<isValid(s);
    return 0;
}
