#include <iostream>

using namespace std;

int main()
{

    int t, r, g, d;
    scanf("%i", &t);

    while (t--)
    {
        scanf("%i %i %i", &r, &g, &d);
        int a = min(r, g);
        int b = max(r, g);
        if ((b - a) / a + (b - a) % a > d)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}