#include <iostream>
#include <algorithm>

using namespace std;
int a[1000006]{};
int b[1000006]{};
int dp[1000006]{};
int main()
{

    int n, res = 1, x;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cin >> b[a[i]];
    }
    sort(a, a + n);

    dp[a[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        dp[a[i]] = 1;

        if (a[i] - b[a[i]] - 1 < 0)
            continue;

        for (int j = a[i] - b[a[i]] - 1; j >= 0; j--)
        {
            if (!b[j])
                continue;

            dp[a[i]] += dp[j];
            break;
        }

        res = max(res, dp[a[i]]);
    }

    cout << n - res;
    return 0;
}
