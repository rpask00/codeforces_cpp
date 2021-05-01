#include <iostream>
using namespace std;

int main()
{

    int dp[103][2]{};
    int mod = 1000000007;

    int n, k, d;
    cin >> n >> k >> d;

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= min(i, k); j++) // j - len of arm witch will be added now
        {
            if (j < d)
                dp[i][0] = (dp[i][0] + dp[i - j][0]) % mod;
            else
                dp[i][1] = (dp[i][1] + dp[i - j][0]) % mod;

            dp[i][1] = (dp[i][1] + dp[i - j][1]) % mod;
        }
    }

    cout << dp[n][1];

    return 0;
}