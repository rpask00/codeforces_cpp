#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int dp[504][504];

int solve(int l, int r)
{
    int &res = dp[l][r];

    if (l > r)
        return 0;
    else if (l == r)
        res = 1;
    else if (!res)
    {
        res = solve(l + 1, r) + 1;
        for (int i = l + 1; i <= r; i++)
        {
            if (s[i] == s[l])
                res = min(res, solve(l + 1, i - 1) + solve(i, r));
        }
    }
    return res;
}

int main()
{

    cin >> n >> s;
    cout << solve(0, n - 1);

    return 0;
}