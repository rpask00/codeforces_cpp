#include <iostream>

using namespace std;

int x[200005]{};
int l[200005]{};
int dp[3][200005]{};
int main()
{

    int n, c;
    scanf("%i", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%i", &c);
        x[c]++;
    }

    for (int i = 1; i <= n + 1; i++)
    {

        int prev = dp[2][i] = min(min(dp[0][i - 1], dp[1][i - 1]), dp[2][i - 1]) + 1;
        if (x[i])
        {
            if (x[i] == 1)
            {
                if (!l[i - 1])
                    l[i - 1] = 1;
                else if (l[i])
                    l[i + 1] = 1;
                else
                    l[i] = 1;
            }
            else if (x[i] == 2)
            {
                if (l[i - 1])
                {
                    l[i] = 1;
                    l[i + 1] = 1;
                }
                else
                {
                    l[i] = 1;
                    l[i - 1] = 1;
                }
            }
            else
            {
                l[i - 1] = 1;
                l[i] = 1;
                l[i + 1] = 1;
            }

            if (x[i - 1])
            {
                dp[0][i] = dp[1][i - 1];
                dp[1][i] = dp[2][i - 1];
            }
            else if (i > 1 and x[i - 2])
            {
                dp[0][i] = dp[2][i - 1];
                dp[1][i] = prev;
            }
            else
            {
                dp[0][i] = prev;
                dp[1][i] = prev;
            }
            dp[2][i] = prev;
        }
        else
        {
            dp[0][i] = dp[0][i - 1];
            dp[1][i] = dp[1][i - 1];
            dp[2][i] = dp[2][i - 1];
        }
    }
    int mx = 0;

    for (int i = 0; i <= n + 1; i++)
        mx += l[i];

    int mn = dp[0][n + 1];
    mn = min(mn, dp[1][n + 1]);
    mn = min(mn, dp[2][n + 1]);

    printf("%i %i\n", mn, mx);

    return 0;
}