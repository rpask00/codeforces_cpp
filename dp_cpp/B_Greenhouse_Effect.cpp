#include <iostream>

using namespace std;

int main()
{
    int dp[50006]{};
    int s[50006];
    int n, m, r = 0;
    float f;
    scanf("%i %i", &n, &m);

    for (int i = 1; i <= n; i++)
        cin >> s[i] >> f;

    for (int i = 1; i <= n; i++)
    {
        int m = 0;
        for (int j = 1; j <= s[i]; j++)
            m = max(m, dp[j]);

        dp[s[i]] = m + 1;
        r = max(r, m + 1);
    }

    printf("%i \n", n - r);

    return 0;
}