#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;
int vis[300001];
int i, j, x, k;
const int MAXN = 500;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> ans;
    set<int> verticies;
    int dp[MAXN + 1][MAXN + 1];
    int cou[MAXN + 1][MAXN + 1];
    vector<tuple<int, int, int>> edges;

    for (i = 0; i <= n; i++)
    {
        if(i)verticies.insert(i);
        for (j = 1; j <= n; j++)
        {
            dp[i][j] = 10000000;
            cou[i][j] = 0;
        }
    }

    for (i = 0; i < m; i++)
    {

        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back(make_tuple(a, b, w));
        dp[a][b] = w;
        dp[b][a] = w;
        dp[a][a] = 0;
        dp[b][b] = 0;
    }

    for (k = 0; k <= n; k++)
    {
        for (i = 0; i <= n; i++)
        {
            if (i == k)
                continue;

            for (j = 0; j <= n; j++)
            {
                if (j == k or j == i)
                    continue;

                if (dp[i][k] + dp[k][j] < dp[i][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }

    for (tuple<int, int, int> edge : edges)
    {
        int a = get<0>(edge);
        int b = get<1>(edge);
        int w = get<2>(edge);

        for (int v : verticies)
        {
            if (dp[v][a] + w == dp[v][b])
                cou[v][b]++;

            if (dp[v][b] + w == dp[v][a])
                cou[v][a]++;
        }
    }

    for (int source : verticies)
    {
        for (i = source + 1; i <= n; i++)
        {
            int count = 0;
            for (int mid : verticies)
            {
                if (dp[source][mid] + dp[mid][i] == dp[source][i])
                    count += cou[source][mid];
            }
            cout << count << ' ';
        }
    }
}
