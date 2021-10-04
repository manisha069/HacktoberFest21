// C++ program for Given an unsorted array arr[] having N elements, the task is to find out the median of the array in linear time complexity.

#include <bits/stdc++.h>
using namespace std;

// Function for calculating
// the median
double findMedian(vector<int> a,
				int n)
{

	// If size of the arr[] is even
	if (n % 2 == 0) {

		// Applying nth_element
		// on n/2th index
		nth_element(a.begin(),
					a.begin() + n / 2,
					a.end());

		// Applying nth_element
		// on (n-1)/2 th index
		nth_element(a.begin(),
					a.begin() + (n - 1) / 2,
					a.end());

		// Find the average of value at
		// index N/2 and (N-1)/2
		return (double)(a[(n - 1) / 2]
						+ a[n / 2])
			/ 2.0;
	}

	// If size of the arr[] is odd
	else {

		// Applying nth_element
		// on n/2
		nth_element(a.begin(),
					a.begin() + n / 2,
					a.end());

		// Value at index (N/2)th
		// is the median
		return (double)a[n / 2];
	}
}

// Driver Code
int main()
{
	// Given array arr[]
	vector<int> arr = { 1, 3, 4, 2,
						7, 5, 8, 6 };

	// Function Call
	cout << "Median = "
		<< findMedian(arr, arr.size())
		<< endl;
	return 0;
}
