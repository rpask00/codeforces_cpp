#include <iostream>

using namespace std;
#define faaaaaast ios_base::sync_with_stdio(false),cin.tie(0)
int a[500005]{};

int main()
{
    int n, x, res = 0;
    faaaaaast;
    scanf("%i", &n);
    for (int i = 1; i <= n; i++)
        scanf("%i", &a[i]);

    for (int mv = 1; mv < 31; mv++)
    {
        int mn = 0;
        int cv = 0;
        for (int i = 1; i <= n; i++)
        {
            cv += a[i] > mv ? -1e9 : a[i];
            mn = min(cv, mn);
            res = max(res, cv - mn - mv);
        }
    }

    cout << res;

    return 0;
}