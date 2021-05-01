#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int ll[200005]{}, rr[200005]{};
vector<long long> x(200005);
int main()
{
    int t;

    scanf("%i", &t);
    while (t--)
    {
        long long n, c, y, k;
        int i, v, l = 0, r = 0, res = 0;
        scanf("%lld %lld", &n, &k);

        ll[n] = 0;
        ll[n + 1] = 0;
        rr[n] = 0;
        rr[n + 1] = 0;

        for (i = 0; i < n; i++)
        {
            scanf("%lld", &c);
            x[i] = c;
        }
        sort(x.begin(), x.begin() + n);

        for (i = 0; i < n; i++)
            scanf("%lld", &c);

        while (r < n)
        {
            v = x[r] - x[l] <= k;
            ll[r + 1] = v ? max(r - l + 1, ll[r]) : ll[r];
            r += v, l += !v;
        }

        r = n, l = n;
        while (l > 0)
        {
            v = x[r - 1] - x[l - 1] <= k;
            rr[l] = v ? max(r - l + 1, rr[l + 1]) : rr[l + 1];
            l -= v, r -= !v;
        }

        for (i = 0; i <= n; i++)
            res = max(res, ll[i] + rr[i + 1]);

        printf("%i \n", res);
    }
    return 0;
}
