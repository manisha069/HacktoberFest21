#include <bits/stdc++.h>
using namespace std;

// d is the number of characters in the input alphabet
#define d 256

/* pat -> pattern
	txt -> text
	q -> A prime number
*/
void search(char pat[], char txt[], int q)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
	int p = 0; // hash value for pattern
	int t = 0; // hash value for txt
	int h = 1;

	// The value of h would be "pow(d, M-1)%q"
	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;
	for (i = 0; i < M; i++)
	{
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}
	for (i = 0; i <= N - M; i++)
	{
		if ( p == t )
		{
			bool flag = true;
			
			for (j = 0; j < M; j++)
			{
				if (txt[i+j] != pat[j])
				{
				flag = false;
				break;
				}
				if(flag)
				cout<<i<<" ";
					
			}
		
			if (j == M)
				cout<<"Pattern found at index "<< i<<endl;
		}
		if ( i < N-M )
		{
			t = (d*(t - txt[i]*h) + txt[i+M])%q;
			if (t < 0)
			t = (t + q);
		}
	}
}
int main()
{
	char txt[] = "RABIN KARP";
	char pat[] = "RABI";
	
	
	int q = 101;
	search(pat, txt, q);
	return 0;
}
