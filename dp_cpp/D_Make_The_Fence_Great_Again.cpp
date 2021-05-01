#include <iostream>
using namespace std;

unsigned long long dp[3][2]{};
unsigned long long MX = (long long)1e18;

int main()
{

    int n, t, a, b, aa;
    cin >> t;

    while (t--)
    {
        scanf("%i %i %i", &n, &aa, &b);
        dp[0][0] = 0;
        dp[1][0] = b;
        dp[2][0] = b + b;
        for (int i = 1; i < n; i++)
        {
            scanf("%i %i", &a, &b);
            for (int j = 0; j < 3; j++)
            {
                dp[j][i % 2] = MX;
                for (int k = 0; k < 3; k++)
                    if (a + j != aa + k)
                        dp[j][i % 2] = min(dp[j][i % 2], dp[k][(i + 1) % 2] + j * b);
            }
            aa = a;
        }

        printf("%lld \n", min(dp[0][(n - 1) % 2], min(dp[1][(n - 1) % 2], dp[2][(n - 1) % 2])));
    }

    return 0;
}
