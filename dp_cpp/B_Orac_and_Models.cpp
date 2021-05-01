#include <iostream>
#include <algorithm> // std::min_element, std::max_element

using namespace std;

int main()
{

    int i, j, n, m, x, y, t;
    int s[100002];
    int dp[100001];

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> s[i + 1];
            dp[i + 1] = 1;
        }

        for (i = 1; i <= n; i++)
            for (j = i; j <= n; j += i)
                if (s[j] > s[i])
                    dp[j] = max(dp[i] + 1, dp[j]);

        printf("%i\n", *max_element(dp + 1, dp + n + 1));
    }

    return 0;
}
