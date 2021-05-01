#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{

    int n, k, p;
    long long ks[2005]{};
    long long w[2005]{};
    scanf("%i %i %i", &n, &k, &p);

    for (int i = 0; i < n; i++)
        scanf("%i", &w[i]);

    for (int i = 0; i < k; i++)
        scanf("%i", &ks[i]);

    sort(ks, ks + k);
    sort(w, w + n);

    long long ans = 1e18;
    for (int i = 0; i <= k - n; i++)
    {
        long long r = 0;
        for (int j = 0; j < n; j++)
            r = max(abs(ks[j + i] - w[j]) + abs(ks[j + i] - p), r);

        ans = min(ans, r);
    }

    printf("%lld \n", ans);

    return 0;
}
