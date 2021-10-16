#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void left_rotate_by_k(int arr[], int n, int k)
{
    k = k % n;
    reverse(arr, arr + k);
    reverse(arr + k, arr + n);
    reverse(arr, arr + n);
    print(arr, n);
}

int main()
{
    int n = 5;
    int k = 2;
    int arr[n] = {1, 2, 3, 4, 5};
    left_rotate_by_k(arr, n, 2);
    return 0;
}
// time complexity=o(n)
// space complexity=o(1)
