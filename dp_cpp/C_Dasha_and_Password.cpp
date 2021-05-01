#include <iostream>
#include <string>

using namespace std;

int main()
{

    int n, m, mx = 1000;
    string ss;
    int dp[55][3]{};
    int sm[10]{};
    scanf("%i %i", &n, &m);

    for (int i = 0; i < 55; i++)
        for (int j = 0; j < 3; j++)
            dp[i][j] = mx, sm[i % 10] = mx;

    for (int i = 0; i < n; i++)
    {
        cin >> ss;
        int j = 0, mn = mx;
        for (char s : ss)
        {
            mn = min(j, m - j);
            
            if (s >= 48 and s <= 57)
                dp[i][0] = min(dp[i][0], mn);
            else if (s >= 97 and s <= 122)
                dp[i][1] = min(dp[i][1], mn);
            else
                dp[i][2] = min(dp[i][2], mn);
            j++;
        }
    }

    for (int i = 0; i < 55; i++)
    {
        int a = dp[i][0], b = dp[i][1], c = dp[i][2];
        for (int j = 0; j < 3; j++)
            sm[6] = min(sm[6], sm[3 + j] + dp[i][j]);

        sm[3] = min(sm[3], b + sm[2]);
        sm[3] = min(sm[3], c + sm[1]);

        sm[4] = min(sm[4], a + sm[2]);
        sm[4] = min(sm[4], c + sm[0]);

        sm[5] = min(sm[5], a + sm[1]);
        sm[5] = min(sm[5], b + sm[0]);

        for (int j = 0; j < 3; j++)
            sm[j] = min(sm[j], dp[i][j]);
    }
    printf("%i \n", sm[6]);

    return 0;
}