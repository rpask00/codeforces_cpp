#include <iostream>
using namespace std;

int cnt[11][101][101]{};

int main()
{

    int n, q, c, x, y, s;
    int x1, y1, x2, y2, t;
    cin >> n >> q >> c;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> s;
        cnt[s][x][y]++;
    }

    for (int p = 0; p < 11; p++)
        for (int i = 0; i < 101; i++)
            for (int j = 0; j < 101; j++)
                cnt[p][i][j] += cnt[p][i - 1][j] + cnt[p][i][j - 1] - cnt[p][i - 1][j - 1];

    for (int _ = 0; _ < q; _++)
    {
        int r = 0;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        for (int p = 0; p < 11; p++)
        {
            int br = (p + t) % (c + 1);
            r += (cnt[p][x2][y2] - cnt[p][x2][y1 - 1] - cnt[p][x1 - 1][y2] + cnt[p][x1 - 1][y1 - 1]) * br;
        }

        printf("%i\n", r);
    }

    return 0;
}
