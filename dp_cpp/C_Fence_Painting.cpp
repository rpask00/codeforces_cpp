#include <iostream>
#include <vector>

using namespace std;

int a[100006]{};
int b[100006]{};
int c[100006]{};

int main()
{

    int t, n, m, ans = 0;

    cin >> t;
    while (t--)
    {
        cin >> n >> m;

        int s1[100006]{};
        int s2[100006]{};
        int c1[100006]{};
        int d[100006]{};
        vector<vector<int>> h(n + 5);
        vector<vector<int>> nd(n + 5);
        vector<int> res;
        int o = 1;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s1[a[i]]++;
            h[a[i]].push_back(i);
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            d[b[i]] = i + 1;
            if (a[i] == b[i])
                s1[a[i]]--;
            else
            {
                s2[b[i]]++;
                nd[b[i]].push_back(i);
            }
        }

        for (int i = 0; i < m; i++)
        {
            cin >> c[i];
            c1[c[i]]++;

            if (s2[c[i]])
                o = nd[c[i]][0] + 1;
        }

        for (int i = 0; i < n; i++)
        {
            if (s2[i] > c1[i])
            {
                ans = 1;
                break;
            }
        }
        if (ans or d[c[m - 1]] == 0)
        {
            cout << "NO\n";
            continue;
        }

        for (int i = 0; i < m; i++)
        {
            int color = c[i];

            if (s1[color])
            {
                s1[color]--;
                res.push_back(o);
            }
            else if (s2[color])
            {
                int u = nd[color].back();
                res.push_back(u + 1);
                nd[color].pop_back();
                s2[color]--;
                a[u] = color;
                if (u == o - 1)
                    o = 0;
            }
            else
            {

                if (d[color] == 0 and o == 0)
                {
                    if (!o)
                    {
                        ans = 1;
                        break;
                    }
                    res.push_back(d[color]);
                }
                else
                    res.push_back(d[c[m - 1]]);
            }
        }

        if (ans)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            for (int r : res)
                cout << r << ' ';
            cout << "\n";
        }
    }

    return 0;
}