#include <iostream>

using namespace std;

int arr[500004];

int r[500004]{};
int l[500004]{};
int f[500004]{};
int s[500004]{};
int dp[500004]{};

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        int color = arr[i];

        if (l[color] == 0)
            l[color] = i + 1;

        r[color] = i + 1;
        f[color]++;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = dp[i + 1];
        int color = arr[i];

        s[color]++;

        if (i == l[color] - 1)
            dp[i] = max(dp[i], f[color] + dp[r[color]]);
        else
            dp[i] = max(dp[i], s[color]);
    }

    cout << n - dp[0];

    return 0;
}