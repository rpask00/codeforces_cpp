#include <iostream>
#include <string>

using namespace std;

int main()
{

    int n, m, t;
    string s;
    int dp[506][506]{};
    char tr[506][506]{};
    scanf("%i", &t);
    while (t--)
    {
        scanf("%i %i", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            cin >> s;
            for (int j = 1; j <= m; j++)
            {
                tr[i][j] = s[j - 1] == '*';
                dp[i][j] = dp[i][j - 1] + tr[i][j];
            }
        }
        int r = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (!tr[i][j])
                    continue;

                for (int h = 0; h < min(n - i + 1, min(m - j + 1, j)); h++)
                {
                    if (dp[i + h][j + h] - dp[i + h][j - (h + 1)] != 2 * h + 1)
                        break;
                    r++;
                }
            }
        }
        printf("%i \n", r);
    }

    return 0;
}