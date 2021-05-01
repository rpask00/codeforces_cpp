#include <iostream>

using namespace std;

int main()
{

    int n, k, x;
    bool dp[505][505]{};
    scanf("%i %i", &n, &k);
    dp[0][0] = 1;
    for (int _ = 0; _ < n; _++)
    {
        scanf("%i", &x);

        for (int i = 500; i >= 0; i--)
        {
            if (x + i > 500)
                continue;

            for (int j = 0; j <= 500; j++)
            {
                if (x + j > 500)
                    continue;

                if (dp[i][j])
                {
                    dp[i + x][j] = dp[i][j];
                    dp[i + x][j + x] = dp[i][j];
                }
            }
        }
    }

    int r = 0;

    for (int i = 0; i <= k; i++)
        r += dp[k][i];

    printf("%i \n", r);

    for (int i = 0; i <= k; i++)
    {
        if (dp[k][i])
            printf("%i ", i);
    }

    return 0;
}