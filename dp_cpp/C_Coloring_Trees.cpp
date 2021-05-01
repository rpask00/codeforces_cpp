#include <iostream>
using namespace std;
const int N = 102;
const long long mx = 1e18;
long long dp[N][N][N]{};
int c[N]{};
int p[N][N];

int main()
{

    int nn, mm, kk, n, m, k, i, j, g, m1, m2;
    scanf("%i %i %i", &nn, &mm, &kk);

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            for (g = 0; g < N; g++)
                dp[i][j][g] = mx;

    for (i = 0; i < N; i++)
        dp[0][i][0] = 0;

    for (i = 1; i <= nn; i++)
        scanf("%i", &c[i]);

    for (i = 1; i <= nn; i++)
        for (j = 1; j <= mm; j++)
            scanf("%i", &p[i][j]);

    for (n = 1; n <= nn; n++)
        if (c[n])
            for (m = 0; m <= mm; m++)
                for (k = n; k >= 1; k--)
                    dp[n][c[n]][k] = min(dp[n][c[n]][k], dp[n - 1][m][k - (m != c[n])]);
        else
            for (m1 = 1; m1 <= mm; m1++)
                for (m2 = 0; m2 <= mm; m2++)
                    for (k = kk; k >= 1; k--)
                        dp[n][m1][k] = min(dp[n][m1][k], dp[n - 1][m2][k - (m1 != m2)] + p[n][m1]);

    

    long long r = mx;
    for (i = 0; i < N; i++)
        r = min(r, dp[nn][i][kk]);

    printf("%lld\n", r == mx ? -1 : r);

    return 0;
}