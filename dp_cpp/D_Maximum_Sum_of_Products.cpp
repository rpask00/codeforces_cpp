#include <iostream>

using namespace std;

long long dp[5005][5005]{};

int main()
{

    int n;
    long long a[5005]{};
    long long b[5005]{};
    long long pp[5005];
    long long res = 0;
    scanf("%i", &n);

    for (int i = 0; i < n; i++)
        scanf("%i", &a[i]);

    for (int i = 0; i < n; i++)
        scanf("%i", &b[i]);

    pp[0] = a[0] * b[0];

    for (int i = 1; i < n; i++)
        pp[i] = pp[i - 1] + a[i] * b[i];

    res = pp[n - 1];

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = a[i] * b[i];
        for (int j = 1; j <= n; j++)
        {
            int l = i - j;
            int r = i + j;

            if (l < 0 or r >= n)
                break;

            dp[l][r] = dp[l + 1][r - 1] + a[l] * b[r] + a[r] * b[l];
            long long curr = dp[l][r] + pp[n - 1] - pp[r];
            if (l - 1 >= 0)
                curr += pp[l - 1];

            res = max(res, curr);
        }

        int g = i + 1;
        dp[i][g] = a[g] * b[i] + a[i] * b[g];
        for (int j = 0; j <= n; j++)
        {
            int l = i - j;
            int r = g + j;

            if (l < 0 or r >= n)
                break;

            dp[l][r] = dp[l + 1][r - 1] + a[l] * b[r] + a[r] * b[l];
            long long curr = dp[l][r] + pp[n - 1] - pp[r];
            if (l - 1 >= 0)
                curr += pp[l - 1];

            res = max(res, curr);
        }
    }

    printf("%lld \n", res);

    return 0;
}