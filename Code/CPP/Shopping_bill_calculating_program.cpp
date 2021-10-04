//This is an interesting program in cpp to calculate your total shopping bill


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

    int n;
    cout << "Enter how many products you bought: ";
    cin >> n;
    cin.ignore(1000, '\n'); // eat the newline

    cout << setprecision(2) << fixed;

    double total = 0.0;

    for (int i = 0; i < n; ++i) {

        string name;
        double price;
        int amount;

        cout << "Enter the name of the product: ";
        getline(cin, name);

        cout << "Enter the price of the product: ";
        cin >> price;

        cout << "Enter the amount bought: ";
        cin >> amount;
        cin.ignore(1000, '\n'); // eat the newline

        double subtotal = price * amount;
        cout << "Your subtotal for " << name << " is: " << subtotal << "\n\n";
        
        total += subtotal;
    }
    
    cout << "Your total is: " << total << '\n';
}
return 0;
}
