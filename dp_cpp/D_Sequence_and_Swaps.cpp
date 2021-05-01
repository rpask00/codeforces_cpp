#include <iostream>
#include <vector>

using namespace std;

int main()
{

    const int N = 503;
    int i, t, n, x, j;
    int arr[N];

    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        for (i = 1; i <= n; i++)
            cin >> arr[i];

        vector<vector<int>> dp(N, vector<int>(N, 1e9));
        dp[0][x] = 0;

        for (i = 1; i <= n; i++)
        {
            vector<vector<int>> cdp(N, vector<int>(N, 1e9));

            for (int prev = 0; prev < N; prev++)
            {
                for (int cx = 0; cx < N; cx++)
                {
                    if (dp[prev][cx] == 1e9)
                        continue;

                    if (arr[i] >= prev)
                        cdp[arr[i]][cx] = min(cdp[arr[i]][cx], dp[prev][cx]);

                    if (prev <= cx and cx < arr[i])
                        cdp[cx][arr[i]] = min(cdp[cx][arr[i]], dp[prev][cx] + 1);
                }
            }
            dp = cdp;
        }

        int a = 1e9;
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                a = min(a, dp[i][j]);

        cout << (a == 1e9 ? -1 : a) << endl;
    }

    return 0;
}