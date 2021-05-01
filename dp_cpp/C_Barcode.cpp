#include <iostream>

using namespace std;

int main()
{

    int n, m, x, y, j;
    int sm[2][1005]{};
    int bc[1005]{};
    int dp[2][1005]{};
    char c;
    scanf("%i %i %i %i", &n, &m, &x, &y);
    scanf("%c", &c);

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%c", &c);
            bc[j] += (c == '#');
        }
        scanf("%c", &c);
    }

    for (int i = 1; i <= m; i++)
    {
        sm[0][i] = sm[0][i - 1] + bc[i];
        sm[1][i] = sm[1][i - 1] + (n - bc[i]);
        dp[0][i] = i <= y ? sm[1][i] : 1e9;
        dp[1][i] = i <= y ? sm[0][i] : 1e9;
    }

    if (m > y or m - x >= x)
    {
        for (int i = 2 * x; i <= m; i++)
        {
            for (j = x; j <= y; j++)
            {
                if (i - j < x)
                    break;

                dp[0][i] = min(dp[0][i], sm[1][i] - sm[1][i - j] + dp[1][i - j]);
                dp[1][i] = min(dp[1][i], sm[0][i] - sm[0][i - j] + dp[0][i - j]);
            }
        }
    }

    printf("%i \n", min(dp[0][m], dp[1][m]));

    return 0;
}