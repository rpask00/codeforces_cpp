#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    int dp[30]{};
    int h[500002][30]{};
    char path[500002]{};
    scanf("%i %i", &n, &k);
    string ss;
    cin >> ss;
    int a = 0, b = 0, x = 1e9, y = 1e9;

    for (int i = 0; i < n; i++)
    {

        int c = ss[i] - 'A';
        for (int j = 0; j < k; j++)
        {
            if (j != x)
            {
                dp[j] = a + (j != c);
                h[i][j] = x;
            }
            else
            {
                dp[j] = b + (j != c);
                h[i][j] = y;
            }
        }

        a = 1e9, b = 1e9, x = 1e9, y = 1e9;
        for (int j = 0; j < k; j++)
        {
            if (dp[j] < a)
            {
                b = a;
                y = x;
                x = j;
                a = dp[j];
            }
            else if (dp[j] < b)
            {
                b = dp[j];
                y = j;
            }
        }
    }
    int r = 1e9;
    int p = 0;
    for (int j = 0; j < k; j++)
    {
        if (r > dp[j])
        {
            r = dp[j];
            p = j;
        }
    }

    path[n - 1] = p;

    int u = 2;
    while (u <= n)
    {
        path[n - u] = h[n - u + 1][p];
        p = path[n - u];
        u++;
    }

    printf("%i \n", r);
    for (int i = 0; i < n; i++)
    {
        printf("%c", path[i] + 'A');
    }

    return 0;
}