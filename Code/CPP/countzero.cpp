#include <iostream>
using namespace std;

int countZeros(int num)
{
    static int count = 0;
    if (num == 0)
        return 1;
    if (num > 0)
    {

        if (num % 10 == 0)
            count++;

        countZeros(num / 10);
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
