#include <iostream>

using namespace std;

int main()
{

    int dp[3]{};
    int n, r = 1, x, y;
    cin >> n >> y;
    dp[1] = 1;
    for (int i = 1; i < n; i++)
    {

        cin >> x;
        if (x > y)
        {
            dp[0] = max(dp[1], dp[2]) + 1;
            dp[2] = 0;
            dp[1] = 1;
            r = max(dp[0], r);
        }
        else if (x == y)
        {
            dp[0]++;
            dp[1]++;
            dp[2]++;
            r = max(dp[0], r);
            r = max(dp[1], r);
            r = max(dp[2], r);
        }
        else
        {
            dp[2] = max(dp[0], dp[1]) + 1;
            dp[0] = 0;
            dp[1] = 1;
            r = max(dp[2], r);
        }
        y = x;
    }

    cout << r;
    return 0;
}