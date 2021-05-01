#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int i, j, n, m;
    int x[100001];
    int h[100001];
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> x[i] >> h[i];

    x[n] = 2000000001;
    int l = 1, r = 0, s = 0;

    for (i = 1; i < n; i++)
    {
        int mx = max({l, r, s});
        if (mx == r and (x[i - 1] + h[i - 1] < x[i] - h[i]))
            l = mx + 1;

        else if (x[i - 1] < x[i] - h[i])
            l = max(l, s) + 1;
        else
            l = mx;

        if (x[i] + h[i] < x[i + 1])
            r = mx + 1;
        else
            r = mx;

        s = mx;
    }

    cout << max({l, r, s});

    return 0;
}