#include <iostream>
using namespace std;

// This program performs a binary search through an array, must be sorted to work
int binarySearch(int array[], int size, int value) 
{   
    int first = 0,         // First array element       
    last = size - 1,       // Last array element       
    middle,                // Mid point of search       
    position = -1;         // Position of search value   
    bool found = false;        // Flag   
    while (!found && first <= last) 
    {      
        middle = (first + last) / 2;     // Calculate mid point      
        if (array[middle] == value)      // If value is found at mid      
    	{         
                found = true;         
                position = middle;      
        }      
        else if (array[middle] > value)  // If value is in lower half         
            last = middle - 1;      
        else         
            first = middle + 1;          // If value is in upper half   
    }   
    return position;
}
int main ()
{
    const int size = 5; // size initialization
    int array[size] = {1, 2, 3, 4, 5}; // declare array of size 10
    int value; // declare value to be searched for
    int result; // declare variable that will be returned after binary search

    cout << "What value would you like to search for? "; // prompt user to enter value
    cin >> value;
    result = binarySearch(array, size, value);

    if (result == -1) // if value isn't found display this message
        cout << "Not found\n";
    else  // If value is found, displays message
        cout << "Your value is in the array.\n"; 
  
    return 0;
}
