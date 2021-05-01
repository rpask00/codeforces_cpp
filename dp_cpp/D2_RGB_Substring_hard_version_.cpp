#include <iostream>
#include <string>

using namespace std;

int dp[3][200005]{};
int main()
{

    int n, q, k;
    string s;
    scanf("%i", &q);
    while (q--)
    {
        int r = 1e9;
        scanf("%i %i", &n, &k);
        cin >> s;

        for (int i = 1; i <= n; i++)
        {
            char c = s[i - 1];
            dp[0][i] = dp[2][i - 1] + (c != 'R');
            dp[1][i] = dp[0][i - 1] + (c != 'G');
            dp[2][i] = dp[1][i - 1] + (c != 'B');

            if (i >= k)
            {
                int m = k % 3;
                r = min(r, dp[0][i] - dp[m == 1 ? 2 : (m == 2 ? 1 : 0)][i - k]);
                r = min(r, dp[1][i] - dp[m == 1 ? 0 : (m == 2 ? 2 : 1)][i - k]);
                r = min(r, dp[2][i] - dp[m == 1 ? 1 : (m == 2 ? 0 : 2)][i - k]);
            }
        }

        printf("%i \n", r);
    }

    return 0;
}