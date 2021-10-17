// Code for Tic Tac Toe Problem
// 1 means X wins, 2 means Y wins and 3 means its a draw
#include <bits/stdc++.h>
using namespace std;

int wincount(vector<string> &v, char key) {
	string s = key == 'X' ? "XXX" : "OOO";
	int count = 0;
	if (v[0] == s) count++;
	if (v[1] == s) count++;
	if (v[2] == s) count++;
	if (v[0][0] == key && v[1][0] == key && v[2][0] == key) count++;
	if (v[0][1] == key && v[1][1] == key && v[2][1] == key) count++;
	if (v[0][2] == key && v[1][2] == key && v[2][2] == key) count++;
	if (v[0][0] == key && v[1][1] == key && v[2][2] == key) count++;
	if (v[0][2] == key && v[1][1] == key && v[2][0] == key) count++;
	return count;
}

void solve(vector<string> &v) {
	int countX = 0;
	int countO = 0;
	int space = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			(v[i][j] == 'X') ? countX++ : (v[i][j] == 'O' ? countO++ : space++);
		}
	}

	if ((countO > countX) || (abs(countX - countO) >= 2)) {
		cout << 3 << endl;
		return ;
	}
	if (space == 9) {
		cout << 2 << endl;
		return;
	}

	int xwin = wincount(v, 'X');
	int owin = wincount(v, 'O');

	if (xwin == 2 && owin == 0 && space == 0) {
		cout << 1 << endl;
		return;
	}
	if (xwin > 1 || owin > 1) {
		cout << 3 << endl;
		return;
	}

	if (xwin != 0 && owin != 0) {
		cout << 3 << endl;
		return ;
	}

	if (xwin == 0 && owin == 1) {
		if (countX == countO) {
			cout << 1 << endl;
			return;
		} else {
			cout << 3 << endl;
			return;
		}
	}

	if (xwin == 1 && owin == 0) {
		if (countX == countO + 1) {
			cout << 1 << endl;
			return;
		} else {
			cout << 3 << endl;
			return;
		}
	}

	if (xwin == 0 && owin == 0) {
		if (space != 0) {
			cout << 2 << endl;
			return;
		}
		else {
			cout << 1 << endl;
			return;
		}

	}


}


int main() {
	int t;
	cin >> t;
	while (t--) {
		string s1;
		string s2;
		string s3;
		cin >> s1;
		cin >> s2;
		cin >> s3;

		vector<string> v;
		v.push_back(s1);
		v.push_back(s2);
		v.push_back(s3);

		solve(v);

	}
}