#include <iostream>

using namespace std;

int dp[2002][2002]{};
int main()
{

    int n, h, l, r, a, t, A;
    scanf("%i %i %i %i", &n, &h, &l, &r);
    int res = 0;
    long long c = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%i", &a);
        c += a;
        for (int j = 0; j < i; j++)
        {
            t = (c - j) % h;
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + (t >= l and t <= r));

            t = (c - 1 - j) % h;
            dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + (t >= l and t <= r));
            res = max(res, dp[i][j]);
            res = max(res, dp[i][j + 1]);
        }
    }
    printf("%i \n", res);

    return 0;
}
