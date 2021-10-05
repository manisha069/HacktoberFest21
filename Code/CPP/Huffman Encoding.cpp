// Problem Name: Huffman Encoding 
//Difficulty Medium
//Topic: Greedy
//You can also practice this problm at GeeksforGeeks(https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1)
//has been asked several times in Amazon interviews


#include<bits/stdc++.h>
using namespace std;


class Minnode
{
    public:
    char val;
    int freq;
    Minnode *left,*right;
   
    Minnode(char cc,int ff)
    {
        val=cc;
        freq=ff;
        left=NULL;right=NULL;
    }
};
class compare {

public:
    bool operator()(Minnode* l, Minnode* r)
 
    {
        return (l->freq > r->freq);
    }
};


class Solution
{
    
    
    
	public:
/*bool compare(Minnode m1,Minnode m2)
    {
        return m1.freq>=m2.freq;
    }
	*/
        void printans(Minnode* root,string s,vector<string>&ans)
        {
            if(root==NULL)
            return;
            if(root->val!='$')
            ans.push_back(s);//huffman val for char root->val
            printans(root->left,s+'0',ans);
            printans(root->right,s+'1',ans);
           
        }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<Minnode*, vector<Minnode*>, compare>pq;
		    
		    Minnode *lft,*rit,*top;
 
		    for(int i=0;i<N;i++)
		    {
		        pq.push(new Minnode(S[i],f[i]));
		    }
		    
		    while(pq.size()!=1)
		    {
		        lft=pq.top();
		        pq.pop();
		        rit=pq.top();
		        pq.pop();
		        top=new Minnode('$',lft->freq+rit->freq);
		        top->left=lft;
		        top->right=rit;
		        pq.push(top);
		    }
		    vector<string>ans;
		    printans(pq.top(),"",ans);
		    return ans;
		    
		}
};


int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
} 
