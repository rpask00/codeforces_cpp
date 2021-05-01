#include <iostream>

using namespace std;

int main()
{

    int n, c, r = 0;
    int dp[10]{};
    scanf("%i", &n);

    int v[] = {4, 8, 15, 16, 23, 42};

    for (int i = 0; i < n; i++)
    {
        scanf("%i", &c);
        if (c == 4)
            dp[0]++;
        else
            for (int j = 0; j < 5; j++)
            {
                if (c != v[j + 1])
                    continue;
                if (dp[j] < dp[j + 1] + 1)
                    r++;
                else
                    dp[j + 1]++;
            }
    }
    for (int i = 0; i < 6; i++)
        r += dp[i] - dp[5];

    printf("%i \n", r);

    return 0;
}