#include <iostream>

using namespace std;
int s[300003];
int dp[300003][3];

int main()
{
    int n, res = 1e9;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 0; i < n; i++)
    {
        cin >> dp[i][0];
        dp[i][1] = 1e9;
        dp[i][2] = 1e9;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int k = 1; k < 3; k++)
            {
                if (s[i] > s[j])
                    dp[i][k] = min(dp[i][k], dp[j][k - 1] + dp[i][0]);

                if (k == 2)
                    res = min(res, dp[i][2]);
            }
        }
    }

    res = res == 1e9 ? -1 : res;
    cout << res;

    return 0;
}