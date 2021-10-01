#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

void formLPS(string pat, vector<int>& lps)
{
    lps[0]=0;
    int m=pat.length(), i=1, j=0;
    while(i<m)
    {
        if(pat[i]==pat[j])
        {
            j++;
            lps[i++]=j;
        }
        else if(j!=0)
        {
            j=lps[j-1];
        }
        else
        {
            lps[i++]=0;
        }
    }
}

void KMP(string text, string pat, vector<int>& lps)
{
    int n=text.length(), m=pat.length(), i=0, j=0;
    while(i<n && j<m)
    {
        if(text[i]==pat[j])
        {
            i++;
            j++;
        }
        else if(j!=0)
        {
            j=lps[j-1];
        }
        else
        {
            i++;
        }
        if(j==m)
        {
            cout<<"Pattern matches at index "<<i-j<<" of the text"<<"\n";
            j=lps[j-1];
        }
    }
}

int main()
{
    string text, pattern;
    getline(cin,text);
    getline(cin,pattern);
    vector<int> lps(pattern.size());
    formLPS(pattern, lps);
    KMP(text, pattern, lps);
    
    return 0;
}