#include <iostream>
#include <string.h>

using namespace std;

int main()
{

    int i, j, n, m, x, y;
    long long r1[100000];
    long long r2[100000];
    long long dp1[2];
    long long dp2[2];

    memset(dp1, 0, 2 * sizeof(int));
    memset(dp2, 0, 2 * sizeof(int));

    cin >> n;

    for (i = 0; i < n; i++)
        cin >> r1[i];

    for (i = 0; i < n; i++)
        cin >> r2[i];

    dp1[0] = r1[0];
    dp2[0] = r2[0];

    for (i = 1; i < n; i++)
    {
        dp1[1] = max(dp1[0], dp2[0] + r1[i]);
        dp2[1] = max(dp2[0], dp1[0] + r2[i]);

        dp1[0] = dp1[1];
        dp2[0] = dp2[1];
    }

    cout << max(dp1[0], dp2[0]);

    return 0;
}