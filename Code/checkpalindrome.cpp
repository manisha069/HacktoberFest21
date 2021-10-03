#include <iostream>
using namespace std;

#include <string.h>
bool checkPalindrome(char input[])
{
    static int i = 0;
    int S = strlen(input);
    if (i >= S)
        return 1;
    if (input[i] != input[S - i - 1])
    {

        return 0;
    }
    else
    {
        i++;
        checkPalindrome(input);
    }
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
