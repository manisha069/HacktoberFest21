// Solution to https://www.codechef.com/START2C/problems/COLGLF5 

#include <bits/stdc++.h>

#define get cin>> 
#define print cout<<
#define fi(s,n) for(int i = s; i < n; i++)
#define fj(s,n) for(int j = s; j < n; j++)
#define fk(s,n) for(int k = s; k < n; k++)
#define inarr(s,n,arr) for (int i = s; i < n; i++) cin>>arr[i];
#define outarr(s,n,arr) for (int i = s; i < n; i++) cout<<arr[i];
#define ll long long
using namespace std;


int code1(){
    
    int cl,fl;
    get fl >>cl;

    vector<int> cric;
    vector<int> foot;

    fi(0,fl){
        int temp;
        get temp;
        foot.push_back(temp);
    }
    fi(0,cl){
        int temp;
        get temp;
        cric.push_back(temp);
    }

    int check = 1;
    // 1 is football. 2 is cricket
    int count=0;

    for(int i =0; i< cl+fl; i++){
        if(cric[i] > foot[i] && check == 1){
            check = 2;
            count ++;
        }
        if(foot[i] > cric[i] && check == 2){
            check = 1;
            count++;
        }
    }

    print count<<"\n";


return 0;
}

int code(){

    int cl,fl;
    get fl >>cl;

    set<int> foot;
    set<int> cric;

    set<int> both;

    fi(0,fl){
        int temp;
        get temp;
        foot.insert(temp);
        both.insert(temp);
    }
    fi(0,cl){
        int temp;
        get temp;
        cric.insert(temp);
        both.insert(temp);
    }

    int kon = 1;
    int r =0;
    int count = 0;
    int len = both.size();

    for(auto it = both.begin(); it != both.end(); ++it){
        auto temp1 = foot.find(*it);
        if(temp1 == foot.end() && r ==0){
            kon = 1;
            r = 1;
            count++;
        }

        auto temp2 = cric.find(*it);
            if(temp2 == cric.end() && r==1){
                kon = 2;
                r = 0;
                count++;
            }
    }

print count <<"\n";
}

int main() {
    int t;
    get t;
    while(t>0){
        code();
        t--;
    }
    return 0;
}