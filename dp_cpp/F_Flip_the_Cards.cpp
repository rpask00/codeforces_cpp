#include <iostream>

using namespace std;
int side[400005];
int os[400005]{};
int t[400005]{};

int main()
{

    // int side[13]{};
    // int os[13]{};
    // int t[13]{};

    int n, x, y, py, yy;
    scanf("%i", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%i %i", &x, &y);
        os[x] = y;
        os[y] = x;
        side[y] = 1;
    }

    int start = 1;
    if (os[1] == 2 * n)
        start++;

    py = 2 * n + 1;
    int pos = start;
    int flip = 0;
    int prog = 0;
    while (prog < n)
    {
        t[pos] = 1;
        t[os[pos]] = 1;
        yy = os[pos] + 1;

        prog++;
        flip += side[pos] != side[start];

        for (int y = yy; y < py; y++)
        {
            if (t[y])
                break;

            prog++;
            t[y] = 1;
            t[os[y]] = 1;

            if ((y + 1 != py and os[y] < os[y + 1]) or os[y] > os[1])
            {
                printf("-1 \n");
                return 0;
            }
            flip += side[y] != side[start];
        }
        py = yy;

        for (pos; pos <= 2 * n; pos++)
            if (!t[pos])
                break;
    }
    int ans = min(flip, n - flip);

    if (start > 1)
    {
        if (flip < n - flip)
            ans += side[1] != side[start];
        else
            ans += side[1] == side[start];
    }

    printf("%i \n", ans);

    return 0;
}