#include <iostream>
#include <vector>
#include <array>

using namespace std;

int i, j, x;
const int maxn = 5005;
array<int, maxn> vis;
array<int, maxn> match;
array<int, maxn> rm;
array<int, maxn> p;
array<int, maxn> c;
array<int, maxn> k;
vector<vector<int>> e(maxn);
vector<int> res;

bool dfs(int v)
{
    for (int club : e[v])
    {
        if (!vis[club])
        {
            vis[club] = 1;
            if (match[club] == -1 or dfs(match[club]))
            {
                match[club] = v;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m, d;
    cin >> n >> m;

    for (i = 0; i < n; i++)
        cin >> p[i];

    for (i = 0; i < n; i++)
        cin >> c[i];

    cin >> d;
    for (i = 0; i < d; i++)
    {
        cin >> k[i];
        rm[k[i]] = 1;
    }

    for (i = 1; i <= n; i++)if (!rm[i])e[p[i-1]].push_back(c[i-1]);
    int mex = 0;
    match.fill(-1);
    for (i = d - 1; i >= 0; i--)
    {
        while (true)
        {
            vis.fill(0);
            if (!dfs(mex))
                break;

            mex += 1;
        }
        e[p[k[i] - 1]].push_back(c[k[i] - 1]);
        res.push_back(mex);
    }

    while (res.size())
    {
        cout << res.back() << endl;
        res.pop_back();
    }
}
