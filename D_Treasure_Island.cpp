#include <iostream>
#include <array>
#include <string>
#include <vector>

using namespace std;
array<int, 1000000> rr;
array<int, 1000000> dd;
array<int, 1000000> vis;
int i, j, x;

int main()
{
    string ss;
    int n, m;
    int index = 1;
    cin >> n >> m;

    for (i = 0; i < n; i++)
    {
        cin >> ss;
        for (j = 0; j < m; j++)
        {
            if (ss[j] == '.')
            {
                if (i)dd[index - m] = index;
                if (j)rr[index - 1] = index;
            }

            index++;
        }
    }
    int res = 0;
    for (i = 0; i < 2; i++)
    {
        vector<int> path;
        int node = 1;
        vis[n * m] = 0;
        res +=1;
        while (node != n * m)
        {
            if (dd[node] and not vis[dd[node]])
            {
                vis[dd[node]] = 1;
                path.push_back(node);
                node = dd[node];
            }

            else if (rr[node] and not vis[rr[node]])
            {
                vis[rr[node]] = 1;
                path.push_back(node);
                node = rr[node];
            }

            else if (path.size())
            {
                node = path.back();
                path.pop_back();
            }
            else
            {
                res-=1;
                break;
            }
        }
    }
    cout << res;
}
