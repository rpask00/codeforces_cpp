#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

typedef int pointer[1003];
int dpe[1003]{};
int dpf[1003]{};
int pf[1003][1003]{};
int pe[1003][1003]{};
int h[900000]{};
int iz = 1e9;
int ix;

int main()
{

    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%i", &x);
            if (x == 0)
            {
                iz = 1;
                ix = i;
                dpf[j] = 1e9;
                dpe[j] = 1e9;
            }

            int uf = 1e9, ue = 1e9;
            int ff = 0, ee = 0;

            while (x and (x % 5) == 0)
            {
                ff++;
                x /= 5;
            }

            while (x and (x % 2) == 0)
            {
                ee++;
                x /= 2;
            }

            if (i != 0)
            {

                uf = dpf[j] + ff;
                ue = dpe[j] + ee;
            }

            if (j != 0)
            {
                int lf = dpf[j - 1] + ff;
                int le = dpe[j - 1] + ee;

                if (lf < uf)
                {
                    uf = lf;
                    pf[i][j] = 1;
                }

                if (le < ue)
                {
                    ue = le;
                    pe[i][j] = 1;
                }
            }

            dpf[j] = i + j ? uf : ff;
            dpe[j] = i + j ? ue : ee;
        }
    }

    string path = "";
    pointer *p = (dpf[--n] < dpe[n]) ? pf : pe;

    if (min(dpf[n], min(dpe[n], iz)) == iz)
    {
        cout << iz << endl;
        path = 'D' * (n - iz) + 'R' * n + 'D' * (iz - 1);
    }
    else
    {
        cout << min(dpf[n], dpe[n]) << endl;
        int i = n, j = n;
        while (i + j != 0)
        {
            p[i][j] ? j-- : i--;
            path += p[i][j] ? 'R' : 'D';
        }
    }

    reverse(path.begin(), path.end());
    cout << path;
    return 0;
}
