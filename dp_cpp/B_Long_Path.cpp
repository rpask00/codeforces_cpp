#include <iostream>

using namespace std;

int main()
{

    int n;
    int p[1005]{};
    int c[1005]{};
    scanf("%i", &n);

    for (int i = 1; i <= n; i++)
        scanf("%i", &p[i]);

    int r = 0;
    int mod = 1000000007;

    for (int i = 1; i <= n; i++)
    {
        c[i] = 2;
        for (int j = p[i]; j < i; j++)
            c[i] = (c[i] + c[j]) % mod;

        r = (r + c[i]) % mod;
    }

    printf("%i \n", r);

    return 0;
}
