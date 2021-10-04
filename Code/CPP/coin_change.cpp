#include <bits/stdc++.h>

std::vector<int> denominations = {1, 3, 4, 5};

int findMinCoins(int value)
{
    //Initializing the result array
    std::vector<int> dp(value+1, value+1);

    //Setting the first element to 0
    dp[0] = 0;

    for(int i = 1; i < dp.size(); i++)
    {
        for(int j = 0; j < denominations.size(); j++)
        {
            if(denominations[j] <= i)
            {
                dp[i] = std::min(dp[i], dp[i-denominations[j]] + 1);
            }
            
        }
    }

    return dp[value] == (value + 1) ? - 1 : dp[value];
}

int main()
{
    int minimum_coins = findMinCoins(7);

    std::cout << minimum_coins << std::endl;

    return 0;
}