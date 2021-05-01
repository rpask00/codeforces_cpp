#include <iostream>
#include <stdlib.h>

using namespace std;
int m[5005][5005];
int a[5005];

int solve(int L, int R, int h)
{
    int l = L;
    int r = R;

    int ans = 0;

    if (l == r)
        return 1;

    for (l; l <= R; l++)
    {
        if (a[l] <= h)
            continue;

        for (r = l; r <= R+1; r++)
        {
            if (a[r] > h)
                continue;
            r--;

            ans += solve(l, r, m[L][R]);
            break;
        }

        l = r;
    }

    return min(R - L + 1, ans + m[L][R] - h);
}

int main()
{

    int n;
    scanf("%i", &n);

    for (int i = 1; i <= n; i++)
        scanf("%i", &a[i]);

    for (int i = 1; i <= n; i++)
    {
        m[i][i] = a[i];
        for (int j = i + 1; j <= n; j++)
            m[i][j] = min(a[j], m[i][j - 1]);
    }
    int res = min(n, m[1][n] + solve(1, n, m[1][n]));

    printf("%i \n", res);

    return 0;
}
