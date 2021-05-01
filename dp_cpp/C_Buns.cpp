#include <iostream>

using namespace std;

int main()
{

    int dp[2][1003]{};
    int n, m, c, d, r = 0;
    scanf("%i %i %i %i", &n, &m, &c, &d);

    for (int i = 1; i <= n / c; i++)
    {
        dp[0][n - i * c] = d * i;
    }

    int e, f, g, h;
    for (int _ = 0; _ < m; _++)
    {
        scanf("%i %i %i %i", &e, &f, &g, &h);

        for (int i = 1; i <= e / f; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (j - i * g < 0)
                    continue;

                dp[1][j - i * g] = max(dp[0][j] + i * h, dp[1][j - i * g]);
            }
        }

        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = max(dp[1][i], dp[0][i]);
            r = max(r, dp[0][i]);
        }
    }

    printf("%i \n", r);

    return 0;
}