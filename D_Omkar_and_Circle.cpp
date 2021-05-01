#include <iostream>
using namespace std;

long long a[200005]{};

long long o[200005]{};
long long e[200005]{};

int main()
{
    int n, x;
    scanf("%i", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%i", &x);
        if (i % 2)
        {
            o[i] = o[i - 1] + x;
            e[i] = e[i - 1];
        }
        else
        {
            o[i] = o[i - 1];
            e[i] = e[i - 1] + x;
        }
        a[i] = x;
    }
    long long res = o[n];

    for (int i = 1; i < n; i++)
    {
        long long v = a[i] + a[i + 1];
        if (i % 2)
        {
            v += e[n] - e[i + 1];
            v += o[max(0, i - 2)];
        }
        else
        {
            v += o[n] - o[i + 1];
            v += e[max(0, i - 2)];
        }
        res = max(res, v);
    }

    printf("%lld \n", res);

    return 0;
}
