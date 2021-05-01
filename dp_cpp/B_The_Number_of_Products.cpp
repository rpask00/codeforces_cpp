#include <iostream>

using namespace std;

int main()
{

    int n, x, y;
    long long rn = 0, rp = 0;
    long long dp[2][2]{};

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;

        dp[0][i % 2] = 0;
        dp[1][i % 2] = 0;

        dp[1][i % 2] = dp[((x < 0) + 1) % 2][(i + 1) % 2];
        dp[0][i % 2] = dp[x < 0][(i + 1) % 2];
        dp[x < 0][i % 2]++;

        rn += dp[1][i % 2];
        rp += dp[0][i % 2];
    }

    cout << rn << " " << rp;

    return 0;
}