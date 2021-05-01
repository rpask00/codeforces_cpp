#include <iostream>

using namespace std;

int main()
{

    int i, j, n, m, x, y,s;
    int arr[200003];
    int dp[200003];
    m = 1;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
        dp[i] = 1;
    }

    for (i = 1; i < n; i++)
    {
        if (arr[i - 1] < arr[i])
        {
            dp[i] = dp[i - 1] + 1;
            m = max(m, dp[i]);
        }
    }

    x = 1;

    for (i = n - 2; i >= 0; i--)
    {
        if (dp[i] + x++ == dp[i + 1])
            dp[i] = dp[i + 1];
        else
            x = 1;
    }

    for (i = 1; i < n - 1; i++)
    {
        if (arr[i] >= arr[i + 1] or arr[i] <= arr[i - 1])
            if (arr[i - 1] < arr[i + 1])
                m = max(m, dp[i - 1] + dp[i + 1] - 1);
    }

    cout << m;
    for (int i = 0; i < n; i++)
    {
        /* code */
    }

    return 0;
}