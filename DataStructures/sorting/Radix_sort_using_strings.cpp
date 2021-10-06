#include <bits/stdc++.h>
using namespace std;

void countSort(vector<string> &v, int n, int p){
	vector<string> output(n);
	int count[10] = {0};
	
	for (int i = 0 ; i < n ; i++ ){
		string s = v[i];
		int l = s.length();
		if (p > l){
			count[0]++;
		}else{
			count[ int(s[l - p]) - 48 ]++;	
		}
	}
	
	for (int i = 1 ; i < 10 ; i++){
		count[i] += count[i-1];
	}
	
	for (int i = n-1 ; i >= 0 ; i--){
		string s = v[i];
		int l = s.length();
		
		if (l < p){
			output[ count[0] - 1 ] = v[i];
			count[0]--;
		}else{
			output[ count[ int(s[l - p]) - 48 ] - 1 ] = v[i];
			count[ int(s[l - p]) - 48 ]--;		
		}
	}
	
	for (int i = 0 ; i < n ; i++){
		v[i] = output[i];
	}
}
void radixSort(vector<string> &v, int n){
	int mx = 0;
	// mx will store the maximum length of string present in vector
	for (int i = 0 ; i < n ; i++){
		int temp = v[i].length();
		mx = max(mx, temp);
	}
	for (int p = 1 ; p <= mx ; p++){
		// countsorting each place of all strings present in vector
		countSort(v, n, p);
	}
}
int main(){
	// taking input from user
    int n; cin >> n;
	vector<string> v(n);
	for (int i = 0 ; i < n ; i++){
		cin >> v[i];
	}
	// radixsort will sort the inputed vector of strings
	radixSort(v, n);
	// output of result
	for (int i = 0 ; i < n ; i++){
		cout << v[i] << endl;
	}
    return 0;
}