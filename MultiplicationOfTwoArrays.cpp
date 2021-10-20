#include<iostream>
using namespace std;

int main()
{
	int size, i, multiarr1[10], multiarr2[10], multiplication[10];

	cout << "\nPlease Enter the Array Size =  ";
	cin >> size;

	cout << "\nPlease Enter the First Array Items =  ";
	for(i = 0; i < size; i++)
	{
		cin >> multiarr1[i];
	}
	cout << "\nPlease Enter the Second Array Items =  ";
	for(i = 0; i < size; i++)
	{
		cin >> multiarr2[i];
	}
	for(i = 0; i < size; i++)
	{
		multiplication[i] = multiarr1[i] * multiarr2[i];
		cout << multiarr1[i] << " * " << multiarr2[i] << " = " << multiplication[i] << "\n";
	}
	cout << "\nThe Final Result of Multiplying two Arrays = ";
	for(i = 0; i < size; i++)
	{
		cout << multiplication[i] << " ";
	}

 	return 0;
}
