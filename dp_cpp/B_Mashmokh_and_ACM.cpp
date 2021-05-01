#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int dp[2005][2005];

int main()
{

    int i, j, n, k, x, y, h;
    cin >> n >> k;

    for (i = 1; i <= n; i++)
        dp[1][i] = 1;

    for (i = 2; i <= k; i++)
    {
        for (j = 1; j <= n; j++)
        {
            dp[i][j] = 0;
        }

        for (j = 1; j <= n; j++)
        {

            for (h = j; h <= n; h += j)
            {
                dp[i][h] = (dp[i][h] + dp[i - 1][j]) % 1000000007;
            }
        }
    }

    int s = 0;
    for (i = 1; i <= n; i++)
    {
        s = (s + dp[k][i]) % 1000000007;
    }

    cout << s;

    return 0;
}