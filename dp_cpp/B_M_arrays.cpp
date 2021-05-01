#include <iostream>

using namespace std;

int main()
{

    int n, t, m, x, r = 0, c = 0;
    int a[100]{};
    int md[100]{};
    scanf("%i", &t);

    while (t--)
    {
        r = 0;
        c = 0;
        scanf("%i %i", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%i", &x);
            a[i] = x;
            md[x % m]++;
        }

        r += a[0] > 1;
        c = a[0] == 1;

        for (int i = 1; i <= m / 2; i++)
        {
            if (md[i] and md[m - i])
                r++;
            else
                c++;
        }

        printf("%i \n", r + (c > 0));

        for (int i = 0; i < m; i++)
            md[i] = 0;
    }

    return 0;
}