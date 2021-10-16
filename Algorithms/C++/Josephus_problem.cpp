#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k)
{
    if (n == 1)
    {
        return 1;
    }
    return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main()
{
    int numberOfpeople = 40, k = 7;
    cout << "The chosen place is " << josephus(numberOfpeople, k);
    return 0;
}
