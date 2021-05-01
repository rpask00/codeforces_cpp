#include <iostream>
#include <vector>
#include <set>
#include <array>

using namespace std;
const int maxn = 200001;
int vis[maxn];
int i, j, x, y;
int main()
{
    int n;
    int redcount = 0;
    cin >> n;
    vector<vector<int>> adj(maxn);
    vector<vector<int>> adjrev(maxn);
    array<int, maxn> reds;
    array<int, maxn> dist;
    reds.fill(0);
    dist.fill(0);

    for (i = 1; i < n; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adjrev[y].push_back(x);
    }

    vector<int> stack;
    stack.push_back(1);
    vis[1] = 1;

    while (stack.size())
    {
        int node = stack.back();
        stack.pop_back();

        for (int green : adj[node])
        {
            if (vis[green])
                continue;

            dist[green] = dist[node] + 1;
            reds[green] = reds[node];

            stack.push_back(green);
            vis[green] = 1;
        }

        for (int red : adjrev[node])
        {
            if (vis[red])
                continue;

            redcount++;
            dist[red] = dist[node] + 1;
            reds[red] = reds[node] + 1;

            stack.push_back(red);
            vis[red] = 1;
        };
    };

    set<int> capitols;
    int flips = maxn;

    for (int root = 1; root <= n; root++)
        flips = min(flips, redcount - 2 * reds[root] + dist[root]);

    for (int root = 1; root <= n; root++)
    {
        int currentflips = redcount - 2 * reds[root] + dist[root];
        if (redcount - 2 * reds[root] + dist[root]; == flips)
            capitols.insert(root);
    }

    cout << flips << endl;
    for (int capitol : capitols)
        cout << capitol << " ";
}
