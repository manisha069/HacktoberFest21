#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of terms\n";
    cin >> n;
    int arr[n];
    printf("Enter data (Only 0,1,2 are allowed)\n");
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Sorting array using DutchNationalFlag (DNF) algorithm
    int low = 0, high = n - 1, mid = 0;
    while (mid <= high)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[low++], arr[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid], arr[high--]);
            break;
        }
    }

    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}