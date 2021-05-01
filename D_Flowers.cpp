#include <iostream>
#include <array>

using namespace std;
int i, j, x;

int main()
{
    int t, k, a, b;
    const int maxn = 100001;
    cin >> t >> k;
    array<long long, maxn> dp1;
    array<long long, maxn> dp2;
    dp1.fill(1);
    dp2.fill(1);

    dp1[0] = 0;
    dp2[0] = 0;
    dp1[k] = 2;

    for (i = 2; i < k; i++)
        dp2[i] = i;

    dp2[k] = k + 1;

    for (i = k + 1; i < maxn; i++)
    {
        dp1[i] = (dp1[i - 1] + dp1[i - k]) % 1000000007;
        dp2[i] = (dp2[i - 1] + dp1[i]) ;
    }

    for (int _ = 0; _ < t; _++)
    {
        cin >> a >> b;
        cout << (dp2[b] - dp2[a - 1] ) % 1000000007 << endl;
    }
}
