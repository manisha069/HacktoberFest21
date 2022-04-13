#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define int long long
#define ld long double
#define endl "\n";

#define f(a,b) for(int i=a;i<b;i++)
#define fr(a,b) for(int i=a;i>b;i--)

const int mod = 1000000007;
using namespace std;

void subsets(char str[], char output[], int i, int j)
{
	if (str[i] == '\0')
	{
		output[j] = '\0';
		cout << output << endl;
		return;
	}

	output[j] = str[i];

	subsets(str, output, i + 1, j + 1);
	subsets(str, output, i + 1, j);


}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while (test--) {

		char str[30];
		cin >> str;

		cin >> str;
		char output[30];
		subsets(str, output, 0, 0);



	}
	return 0;
}
