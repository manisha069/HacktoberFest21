#include <iostream>
using namespace std;

int main() {
    int x;
    long double factorial = 1.0;

    cout << "Enter integer = ";
    cin >> x;

    if (x < 0)
        cout << "Please enter positive integer!";
    else {
        for(int i = 1; i <= x; ++i) {
            factorial *= i;
        }
        cout << "Factorial of " << x << " = " << factorial;
    }

    return 0;
}
