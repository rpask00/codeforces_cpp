#include <iostream>
#include <algorithm>

using namespace std;

int dp[202][202][202]{};
int main()
{
    int R, G, B, x = 0, area = 0;
    int r[202];
    int g[202];
    int b[202];
    cin >> R >> G >> B;

    for (int i = 0; i < R; i++)
        cin >> r[i];

    for (int i = 0; i < G; i++)
        cin >> g[i];

    for (int i = 0; i < B; i++)
        cin >> b[i];

    sort(r, r + R, greater<int>());
    sort(g, g + G, greater<int>());
    sort(b, b + B, greater<int>());

    for (int ri = 0; ri <= R; ri++)
    {
        for (int gi = 0; gi <= G; gi++)
        {
            for (int bi = 0; bi <= B; bi++)
            {
                x = 0;
                if (ri and bi)
                    x = max(x, dp[ri - 1][gi][bi - 1] + r[ri - 1] * b[bi - 1]);
                if (gi and bi)
                    x = max(x, dp[ri][gi - 1][bi - 1] + g[gi - 1] * b[bi - 1]);
                if (ri and gi)
                    x = max(x, dp[ri - 1][gi - 1][bi] + r[ri - 1] * g[gi - 1]);

                area = max(area, x);
                dp[ri][gi][bi] = x;
            }
        }
    }

    cout << area;

    return 0;
}