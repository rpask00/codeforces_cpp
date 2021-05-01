#include <iostream>

using namespace std;
int a[500006];
int g[500006]{};
int dp[500006]{1};

int main()
{
    int n;
    cin >> n;
    cin >> a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        dp[i] = (a[i] > a[i - 1] ? dp[i - 1] + 1 : 1);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        g[i] = (g[i + 1] + 1) % 3;
        for (int j = 1; j < dp[i]; j++)
        {
            dp[i - j] = dp[i];
            g[i - j] = g[i];
        }

        i -= dp[i] - 1;
    }

    int m = min(n, 2);

    for (int i = 1; i < n; i++)
    {
        if (g[i - 1] != g[i + 1])
        {
            if (a[i - 1] + 1 < a[i + 1])
                m = max(m, dp[i - 1] + dp[i + 1]);

            if (a[i - 1] >= a[i])
                m = max(m, dp[i - 1] + 1);
            else
                m = max(m, dp[i - 1]);

            if (a[i + 1] > a[i])
                m = max(m, dp[i + 1]);
            else
                m = max(m, dp[i + 1] + 1);
        }

        if (g[i - 1] != g[i])
        {
            m = max(m, dp[i - 1] + 1);
            m = max(m, dp[i + 1] + 1);
        }
    }

    printf("%i", m);

    return 0;
}