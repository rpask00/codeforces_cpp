#include <iostream>

using namespace std;

int main()
{

    long long dpb[1006]{};
    long long dpa[1006]{};
    int n, m, res = 0, mod = 1000000007;

    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        dpb[i] = 1;
        dpa[i] = 1;
    }

    for (int _ = 1; _ < m; _++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                dpb[i] = (dpb[i] + dpb[j]) % mod;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        dpa[i + 1] = dpb[n - i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            res = (res + dpa[i] * dpb[j]) % mod;
        }
    }

    cout << res;

    return 0;
}