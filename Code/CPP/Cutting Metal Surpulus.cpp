#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &rods, int sz, int cpc, int sl) {
	int pr = 0;
	for(int r : rods) {
    	int temp = 0;
    	if(r%sz == 0) {
        	temp += ((r/sz) * sz * sl) - (r/sz - 1) * cpc;
    	} else {
        	temp += ((r/sz) * sz * sl) - (r/sz) * cpc;
    	}
    	if(temp > 0) pr += temp;
	}
	return pr;
}

int main() {
	int n;
	int cpc , sl;
	cin >> cpc >> sl;
	cin >> n;
	vector<int> v(n);
	int maxlen = 0;
	for(int i=0; i<n; i++) {
    	cin >> v[i];
    	maxlen = max(maxlen, v[i]);
	}

	int ans = INT_MIN;
	for(int sz=1; sz<=maxlen; sz++) {
    	int prof = solve(v, sz, cpc, sl);
    	ans = max(prof, ans);
	}
	cout <<ans << endl;
	return 0;
}

