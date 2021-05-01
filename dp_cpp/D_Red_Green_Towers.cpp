#include <iostream>

using namespace std;

int dp[200005][2]{};
int main()
{
    int r, g, t = 2;
    scanf("%i %i", &r, &g);

    if (!r or !g)
    {
        printf("1\n");
        return 0;
    }

    dp[0][1] = 1;
    dp[1][1] = 1;

    for (t = 2; t < 900; t++)
    {
        int cs = (2 + (t - 1)) * t / 2;
        if (cs > r + g)
            break;

        for (int i = 0; i <= min(cs, r); i++)
        {
            if (cs - i > g)
            {
                dp[i][t % 2] = 0;
                continue;
            }

            dp[i][t % 2] = dp[i][(t + 1) % 2];

            if (i >= t)
                dp[i][t % 2] = (dp[i][t % 2] + dp[i - t][(t + 1) % 2]) % 1000000007;
        }
    }

    t--;

    int ans = 0;

    for (int i = 0; i <= r; i++)
        ans = (ans + dp[i][t % 2]) % 1000000007;

    printf("%i \n", ans);

    return 0;
}