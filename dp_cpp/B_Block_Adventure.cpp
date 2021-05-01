#include <iostream>
using namespace std;

int main()
{
    int i, j, n, m, x, y, t, k;

    cin >> t;

    for (int _ = 0; _ < t; _++)
    {
        y = 1;
        int h[200];
        cin >> n >> m >> k;
        for (j = 0; j < n; j++)
            cin >> h[j];

        for (i = 0; i < n - 1; i++)
        {
            if (h[i] >= h[i + 1])
            {
                m += h[i] - h[i + 1];
                m += min(k, h[i + 1]);
            }
            else
            {
                x = h[i + 1] - h[i];

                if (x < k)
                {
                    m += min(h[i], k - x);
                    continue;
                }

                if (x - m > k)
                {
                    cout << "NO" << endl;
                    y = 0;
                    break;
                }

                m -= (x - k);
            }
        }
        if (y)
            cout << "YES" << endl;
    }

    return 0;
}