#include <bits/stdc++.h>

using namespace std;
int a[300004]{};
int b[300004]{};
int dpl[300004][2]{};
int dpw[300004][2]{};
int ml[300004]{};
int main()
{
    int n, m, x, r = 0;
    vector<pair<int, int>> w;
    scanf("%i %i", &n, &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%i %i %i", &a[i], &b[i], &x);
        ml[x]++;
        w.push_back(make_pair(x, i));
    }

    sort(w.begin(), w.end());

    vector<int> ch;
    for (pair<int, int> p : w)
    {

        int i = p.second;
        ml[p.first]--;
        if (dpl[a[i]][0] + 1 > dpl[b[i]][0] and dpw[a[i]][0] < p.first)
        {
            dpl[b[i]][1] = max(dpl[a[i]][0] + 1, dpl[b[i]][1]);
            dpw[b[i]][1] = p.first;
            ch.push_back(b[i]);
        }

        if (ml[p.first] == 0)
        {
            for (int c : ch)
            {
                dpl[c][0] = max(dpl[c][0], dpl[c][1]);
                dpw[c][0] = dpw[c][1];
                r = max(dpl[c][0], r);
            }
            ch.clear();
        }
    }

    printf("%i \n", r);

    return 0;
}