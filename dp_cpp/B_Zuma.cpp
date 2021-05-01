#include <iostream>

using namespace std;

int main()
{

    int n;
    int c[504];
    int dp[503][503]{};

    scanf("%i", &n);
    for (int j = 1; j <= n; j++)
        scanf("%i", &c[j]);

    for (int j = 1; j <= n; j++)
        for (int i = j; i > 0; i--)
        {
            dp[i][j] = dp[i][j - 1] + 1;
            for (int k = i; k < j; k++)
            {
                if (c[k] != c[j])
                    continue;

                dp[i][j] = min(dp[i][j], dp[i][k - 1] + max(1, dp[k + 1][j - 1]));
            }
        }

    printf("%i \n", dp[1][n]);

    return 0;
}
