#include <iostream>
using namespace std;

const int N = 5000005;
int dp[N]{};

int main()
{
    int a, b, t, i, j, k;
    for (i = 2; i < N; i++)
    {
        if (!dp[i])
            for (j = 1; j * i < N; j++)
            {
                int x = i * j;
                while (!(x % i))
                {
                    dp[i * j]++;
                    x /= i;
                }
            }

        dp[i] += dp[i - 1];
    }

    scanf("%i", &t);
    while (t--)
    {
        scanf("%i %i", &a, &b);
        printf("%i \n", dp[a] - dp[b]);
    }
    return 0;
}