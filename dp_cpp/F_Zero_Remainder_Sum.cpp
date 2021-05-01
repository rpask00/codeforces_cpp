#include <iostream>

using namespace std;

int res[70][75]{};
int main()
{
    int n, m, k, now;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> now;
        int dp[2][74][74]{};
        dp[0][1][now % k] = now;

        for (int j = 1; j < m; j++)
        {
            cin >> now;
            for (int g = 0; g <= min((m / 2), j); g++)
            {
                for (int h = 0; h < k; h++)
                {
                    int *prevh = &dp[(j - 1) % 2][g][h];

                    if (not *prevh and h)
                        continue;

                    int *currh = &dp[j % 2][g][h];
                    *currh = max(*currh, *prevh);
                    res[i][h] = max(res[i][h], *currh);

                    if (g != (m / 2))
                    {
                        int nmod = (h + now) % k;
                        int *currMod = &dp[j % 2][g + 1][nmod];

                        *currMod = max(*prevh + now, *currMod);
                        res[i][nmod] = max(res[i][nmod], *currMod);
                    }
                }
            }
        }
    }

    int fin[72]{};
    for (int i = 1; i < max(n, 2); i++)
    {
        if (i > 1)
            for (int c = 0; c < k; c++)
                res[i - 1][c] = fin[c];

        for (int p = 0; p < k; p++)
            for (int c = 0; c < k; c++)
            {
                int v = res[i - 1][p] + res[i][c];
                fin[v % k] = max(fin[v % k], v);
            }
    }

    cout << fin[0];

    return 0;
}