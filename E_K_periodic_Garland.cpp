#include <iostream>
#include <string>

using namespace std;
int c[1000002];
int b[1000002];

int main()
{

    int t;
    c[0] = 0;
    b[0] = 0;
    scanf("%i", &t);
    while (t--)
    {

        int n, k;
        string ss;
        scanf("%i %i", &n, &k);
        cin >> ss;

        for (int i = 0; i < n; i++)
            c[i + 1] = c[i] + (ss[i] == '1');

        for (int i = 0; i < n; i++)
        {
            b[i + 1] = c[i] + (ss[i] == '0');
            if (i >= k)
                b[i + 1] = min(b[i + 1], b[i + 1 - k] + c[i] - c[i + 1 - k] + (ss[i] == '0'));
        }
        int r = c[n];

        for (int i = 0; i < n; i++)
            r = min(r, b[n - i] + c[n] - c[n - i]);

        printf("%i \n", r);
    }
    return 0;
}