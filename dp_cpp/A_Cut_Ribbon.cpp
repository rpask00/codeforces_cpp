#include <iostream>

using namespace std;

int main()
{

    int n, a, b, c;
    int dp[4002];
    cin >> n >> a >> b >> c;

    dp[a] = 1;
    dp[b] = 1;
    dp[c] = 1;

    int m = a;
    m = min(m, b);
    m = min(m, c);

    for (int i = 0; i <= n; i++)
    {
        dp[i] = 0;
    }

    int r = 0;

    dp[a] = 1;
    dp[b] = 1;
    dp[c] = 1;

    for (int i = m; i < n+1; i++)
    {
        m = 0;
        if (i >= a and dp[i - a])
        {
            m = max(dp[i - a] + 1, m);
        }
        if (i >= b and dp[i - b])
        {
            m = max(dp[i - b] + 1, m);
        }
        if (i >= c and dp[i - c])
        {
            m = max(dp[i - c] + 1, m);
        }

        if(m)
            dp[i] = m;

        r = max(r, dp[i]);
    }

    cout << dp[n];

    return 0;
}