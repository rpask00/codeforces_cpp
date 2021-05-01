#include <iostream>

using namespace std;
int i, j, x;

int main()
{
    int v;
    cin >> v;
    int a[11];
    long long dp[100001];

    for (i = 1; i < 10; i++)
    {
        cin >> x;
        a[i] = x;
    }
    dp[0] = 0;

    for (i = 1; i <= v; i++)
    {
        long long maxval = 0;
        dp[i] = 0;
        for (j = 1; j < 10; j++)
        {
            if (a[j] > i)
                continue;

            maxval = max(dp[i - a[j]] * 10 + j, maxval);
        }
        dp[i] = max(maxval, dp[i - 1]);
        cout << dp[i] << endl;
    }

    if (dp[v])
        cout << dp[v];
    else
        cout << -1;
}
