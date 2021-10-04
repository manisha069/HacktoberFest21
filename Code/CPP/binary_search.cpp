#include <iostream>

using namespace std;

int binary_search(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middlei itself

        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // It can only be present in left subarray
        if (arr[mid] > x)
            return binary_search(arr, l, mid - 1, x);

        // Else the element can only be present in right subarray
        return binary_search(arr, mid + 1, r, x);
    }

    // If element is not present in array
    return -1;
}

int main(void)
{
    int size;
    cout<<"Enter array size: ";
    // Getting user input for array size.
    cin>>size;
    int arr[size];
    cout<<"Enter array elements: \n";
    // Getting the values in array using traversal through for loop.
    for(int i = 0; i<size;i++){
        cin>>arr[i];
    }
    cout<<"Enter element to search: ";
    int x;
    cin>>x;
    int n = sizeof(arr) / sizeof(arr[0]);
    int answer = binary_search(arr, 0, size - 1, x);
    (answer == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index: " << answer;
    return 0;
}
