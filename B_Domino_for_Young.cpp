#include <iostream>

using namespace std;

int main()
{

    int n, x, b = 0;
    scanf("%i", &n);
    long long c[2]{};

    for (int i = 0; i < n; i++)
    {
        scanf("%i", &x);
        c[0] += x / 2;
        c[1] += x / 2;

        c[b] += x % 2;
        b = (b + 1) % 2;
    }

    printf("%lld \n", min(c[0], c[1]));

    return 0;
}
