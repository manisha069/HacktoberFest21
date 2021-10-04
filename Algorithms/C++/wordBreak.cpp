/**
 * code by : gursimran18
 * Ques :dictionary of words dict of length n is given , 
 * also given a string s 
 * TASK: add spaces in s to construct a sentence 
 * where each word is a valid dictionary word. 
 * Each dictionary word can be used more than once. 
 * Print all such possible sentences.
 * */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string>ans;
vector<string>sentence;
//function to break the string into possible sentences!
void wordBreakutil(int l,int n,string s,vector<string>&dict) 
{
    if (l == n)
    {
        string st="";
        for(int p=0;p<sentence.size()-1;p++)
        {
            st+=sentence[p]+' ';
        }
        st+=sentence[sentence.size()-1];
        ans.push_back(st);
        return;
    }
        
    for (int i = l; i < n; i++) {
    if (find(dict.begin(), dict.end(), s.substr(l, i - l + 1)) != dict.end()) 
    {
        sentence.push_back(s.substr(l, i - l + 1));
        wordBreakutil(i + 1, n,s,dict);
        sentence.pop_back();
    }

    }
    
}
vector<string> wordBreak(int n, vector<string>& dict, string s)
{
    ans.clear();
    wordBreakutil(0,s.size(),s,dict);
    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
    int n;
    vector<string> dict;
    string s;
    cout<<"enter length of dictionary:\n";
    cin>>n;
    cout<<"enter "<<n<<" words:\n";
    for(int i = 0;i < n;i++){
        cin>>s;
        dict.push_back(s);
    }
    cout<<"enter string from which sentences are supposed to be formed:\n";
    cin>>s;
    vector<string> result = wordBreak(n, dict, s);
    if(result.size() == 0)
        cout<<"No sentence formation possible\n";
    else{
        sort(result.begin(), result.end());
        for(int i = 0;i < result.size();i++)
            cout<<"("<<result[i]<<")";
        cout<<endl;
        }
    
    return 0;
} 