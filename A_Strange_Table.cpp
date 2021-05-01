#include <iostream>

using namespace std;

int main()
{

    int t;
    scanf("%i", &t);
    while (t--)
    {
        long long m, n, x;
        scanf("%lld %lld %lld", &n, &m, &x);

        long long r = (x - 1) % n + 1;
        long long c = (x / n) +( (x%n) != 0);

        long long v = (r - 1) * m + c;
        printf("%lld \n", v);
    }

    return 0;
}