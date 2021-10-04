// Solution to https://www.codechef.com/LTIME92C/problems/INTRVS

#include <iostream>
#include<cmath>
using namespace std;

int code(){
int N,k;
cin>>N>>k;
int xceal = ceil(N/2);
//cout<<"ceil is "<<xceal<<"\n";
int yceal=0;
int n[N];
int bot=0;
int sol =0;
for(int i=0; i<N; i++){
    cin>>n[i];
}
int time=0,bt=0;
for(int i=0; i<N; i++){
    if(n[i]==-1){
        yceal++;
    }
    //LaterMate
    if(n[i]>k){
        time=1;
    }
    //Bot
    if(n[i]==0 || n[i]==1){
        bt++;
    }
}
if(yceal > xceal){
    cout<<"Rejected\n";
}
else if(time==1){
    cout<<"Too slow\n";
}
else if(bt==N){
    cout<<"Bot\n";
}
else{
    cout<<"Accepted\n";
}
}
int main() {
	int t;
    cin>>t;
    while(t>0){
        code();
        t--;
    }
	return 0;
}
