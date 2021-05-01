#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;
const int MAXN = 70;
int dp[MAXN][MAXN][MAXN][MAXN];
int matrix[MAXN][MAXN];
int i, j, x, y;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> x;
            matrix[i][j] = x;
        }
    }

    for (i = 0; i < MAXN; i++)
    {
        for (j = 0; j < MAXN; j++)
        {
            for (int k = 0; k < MAXN; k++)
            {
                for (int d = 0; d < MAXN; d++)
                {
                    dp[i][j][k][d] = -10000000;
                }
            }
        }
    }
    dp[0][0][0][0] = 0;

    for (x = 0; x < n; x++)
    {
        for (y = 0; y < m; y++)
        {
            for (int cnt = 1; cnt < m / 2 + 1; cnt++)
            {
                for (int rest = 1; rest < k; rest++)
                {
                    int nj = (j == m - 1 ? 0 : j + 1);
                    int ni = (j == m - 1 ? i + 1 : i);

                    if (ni != i)
                        dp[ni][nj][0][rest] = max(dp[ni][nj][0][rest], dp[i][j][cnt][rest]);
                    else
                        dp[ni][nj][cnt][rest] = max(dp[ni][nj][cnt][rest], dp[ni][j][cnt][rest]);

                    if (cnt + 1 > m / 2)
                        continue;

                    int nrest = (rest + matrix[i][j]) % k;

                    if (ni != i)
                        dp[ni][nj][0][nrest] = max(dp[ni][nj][0][nrest], dp[i][j][cnt][rest] + matrix[i][j]);
                    else
                        dp[ni][nj][cnt + 1][nrest] = max(dp[ni][nj][cnt + 1][nrest], dp[ni][j][cnt][rest] + matrix[i][j]);
                }
            }
        }
    }
    cout << max(dp[n][0][0][0], 0) << endl;
}
