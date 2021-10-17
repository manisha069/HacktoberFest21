#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<char>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

//cout << fixed << setprecision(10);
//sorting
/* int n = sizeof(arr) / sizeof(arr[0]);
     sort(arr, arr + n);*/
//__gcd(m, n)
bool isVowel(char ch)
{
    if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        return true;
    return false;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int qi = 0; qi < t; qi++)
    {
        string s;
        cin >> s;
        vi alphabet(27, 0);
        int vowel = 0;
        int consonant = 0;
        for (int i = 0; i < s.size(); i++)
        {
            alphabet[s[i] - 'A' + 1]++;
            if (isVowel(s[i]))
                vowel++;
            else
            {
                consonant++;
            }
        }
        int max_freq = 0;
        int ch = -1;
        for (int i = 0; i < 27; i++)
        {
            if (alphabet[i] > max_freq)
            {
                max_freq = alphabet[i];
                ch = i;
            }
        }
        cout << "Case #" << qi + 1 << ": ";
        if (max_freq == s.size())
            cout << "0"
                 << "\n";
        else if (vowel == 0 || consonant == 0)
            cout << s.size() << "\n";
        else
        {
            int fans = INT_MAX;
            for (int i = 1; i < 27; i++)
            {
                if (alphabet[i] > 0)
                {
                    if (isVowel('A' + i - 1))
                        fans = min(consonant + 2 * (vowel - alphabet[i]), fans);
                    else
                        fans = min(fans, vowel + 2 * (consonant - alphabet[i]));
                }
            }
            cout << fans << "\n";
        }
    }
    return 0;
}