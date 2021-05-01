#include <iostream>

using namespace std;

int main()
{

    int dp[2]{};
    int n, x, a, b;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;

        if (x % 2)
        {
            a = dp[1] ? max(dp[0] + x, dp[1]) : dp[0] + x;
            b = max(dp[1] ? dp[1] + x : dp[0], dp[0]);
            dp[1] = a;
            dp[0] = b;
        }
        else
        {
            a = dp[1] ? max(dp[1] + x, dp[1]) : 0;
            b = max(dp[0] + x, dp[0]);
            dp[1] = a;
            dp[0] = b;
        }
    }

    cout << dp[1];

    return 0;
}
