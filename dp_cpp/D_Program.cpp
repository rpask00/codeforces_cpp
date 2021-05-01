#include <iostream>
#include <string>

using namespace std;

int mf[200005]{};
int xf[200005]{};
int mb[200005]{};
int xb[200005]{};
int c[200005]{};

int main()
{

    int t, n, l, r, q;
    string s;
    cin >> t;
    while (t--)
    {
        scanf("%i%i", &n, &q);
        mb[n + 1] = 0;
        xb[n + 1] = 0;
        cin >> s;
        for (int i = 1; i <= n; i++)
        {

            c[i] = c[i - 1] + (s[i - 1] == '+' ? 1 : -1);
            mf[i] = min(mf[i - 1], c[i]);
            xf[i] = max(xf[i - 1], c[i]);
        }

        for (int i = n; i > 0; i--)
        {
            int d = (s[i - 1] == '+' ? 1 : -1);
            mb[i] = min(0, d + mb[i + 1]);
            xb[i] = max(0, d + xb[i + 1]);
        }

        for (int i = 0; i < q; i++)
        {
            scanf("%i%i", &l, &r);
            l--, r++;

            int m1 = mf[l], x1 = xf[l];
            int m2 = mb[r] + c[l], x2 = xb[r] + c[l];
            printf("%i \n", max(x1, x2) - min(m1, m2) + 1);
        }
    }

    return 0;
}
