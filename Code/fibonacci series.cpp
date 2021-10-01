#include <iostream>
using namespace std;

int main() {
    int n, t1 = 0, t2 = 1, nextTerm = 0;

    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: ";

    for (int i = 1; i <= n; ++i) 
    {
        cout<<nextTerm<<" ";
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1+t2;
    }
    return 0;
}
