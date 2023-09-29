#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

void printLatestVersion(string str1, string str2){
    
    int n = str1.length();
    int m = str2.length();
    
    int i=0, j=0;
    
    int num1, num2;
    
    string candidate = "";
    
    while(i<n && j<m){
        string s1 = "", s2 = "";
        
        while(i<n && str1[i]!='.') s1 += str1[i++];
        
        while(j<m && str2[j]!='.') s2 += str2[j++];
        
        try{
            num1 = stoi(s1);
            num2 = stoi(s2);    
        }catch(...){
            cout<<"Invalid version number\n";
            break;
        }
        
        
        if(num1 < num2){
            candidate = str1;
        }else if(num2 < num1){
            candidate = str2;
        }else{
            // if equal but one get exhausted like 1.1.0.1 && 1.1.0 then the exhausted one is candidate
            
            if(i==n && j==m){
                cout<<"Both are the same version\nYou may have entered it wrong\n";
                break;
            }else if(i==n){
                candidate = str1;
            }else if(j==m){
                candidate = str2;
            }
        }
        
        if(candidate.length() != 0){
            cout<<"The latest version is : " << candidate << endl;
            break;
        }
        
        i++;
        j++;
    }
    
}

int main() {
	string str1, str2;
	cin>>str1>>str2;
	printLatestVersion(str1, str2);
	return 0;
}
