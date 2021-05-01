#include <bits/stdc++.h>

using namespace std;

long long dpv[2003][2003];
int a[2003];

long long dp(int l, int r)
{
    if (dpv[l][r] != -1)
        return dpv[l][r];

    if (l == r)
        return 0;

    dpv[l][r] = a[r] - a[l] + min(dp(l + 1, r), dp(l, r - 1));
    return dpv[l][r];
}

int main()
{

    int n;
    scanf("%i", &n);

    for (int i = 0; i < n; i++)
        scanf("%i", &a[i]);

    sort(a, a + n);
    memset(dpv, -1, sizeof(dpv));

    printf("%lld \n", dp(0, n - 1));

    return 0;
}