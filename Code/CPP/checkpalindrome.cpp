#include <iostream>
using namespace std;

#include <string.h>
bool checkPalindrome(char input[])
{
    static int i = 0;
    int N = strlen(input);
    for(int i = 0; i<N/2; i++) 
    {
        if(input[i] != input[N-i-1]) 
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char input[50];
    cin >> input;

    if (checkPalindrome(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
