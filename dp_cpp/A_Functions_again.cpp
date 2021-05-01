#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n, x, y;
    long long a, res = -1e9, dpn = -1e9, dpp = -1e9;

    cin >> n >> x;
    for (int i = 1; i < n; i++)
    {
        cin >> y;
        a = abs(y - x) * (i % 2 ? -1 : 1);
        dpn = max(a, dpn + a);
        dpp = max(-a, dpp + -a);
        res = max(res, max(dpn, dpp));
        x = y;
    }

    cout << res;

    return 0;
}