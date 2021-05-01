#include <iostream>

using namespace std;

int arr[1003][1003];
int dp[4][1003][1003]{};

int main()
{
    int n, m, r = 0, g, a, b, i, j;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            cin >> arr[i][j];

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            dp[0][i][j] = max(dp[0][i - 1][j], dp[0][i][j - 1]) + arr[i][j];
            g = m - j + 1;
            dp[2][i][g] = max(dp[2][i - 1][g], dp[2][i][g + 1]) + arr[i][g];
        }

    for (i = n; i > 0; i--)
        for (j = 1; j <= m; j++)
        {
            dp[1][i][j] = max(dp[1][i + 1][j], dp[1][i][j - 1]) + arr[i][j];
            g = m - j + 1;
            dp[3][i][g] = max(dp[3][i + 1][g], dp[3][i][g + 1]) + arr[i][g];
        }

    for (i = 2; i < n; i++)
        for (j = 2; j < m; j++)
        {
            a = dp[0][i - 1][j] + dp[3][i + 1][j] + dp[1][i][j - 1] + dp[2][i][j + 1];
            b = dp[1][i + 1][j] + dp[2][i - 1][j] + dp[0][i][j - 1] + dp[3][i][j + 1];
            r = max(r, max(a, b));
        }

    cout << r;
    return 0;
}