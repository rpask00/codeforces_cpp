#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define NIL 0
#define INF INT_MAX

class BipGraph
{
    int m, n;
    list<int> *adj;
    int *pairU, *pairV, *dist;

public:
    BipGraph(int m, int n);
    void addEdge(int u, int v);
    bool bfs();
    bool dfs(int u);
    int hopcroftKarp();
};

int BipGraph::hopcroftKarp()
{
    pairU = new int[m + 1];
    pairV = new int[n + 1];
    dist = new int[m + 1];

    for (int u = 0; u <= m; u++)
        pairU[u] = NIL;
    for (int v = 0; v <= n; v++)
        pairV[v] = NIL;

    int result = 0;
    while (bfs())
    {
        for (int u = 1; u <= m; u++)
            if (pairU[u] == NIL && dfs(u))
                result++;
    }
    return result;
}

bool BipGraph::bfs()
{
    queue<int> Q;
    for (int u = 1; u <= m; u++)
    {

        if (pairU[u] == NIL)
        {

            dist[u] = 0;
            Q.push(u);
        }
        else
            dist[u] = INF;
    }

    dist[NIL] = INF;

    while (!Q.empty())
    {

        int u = Q.front();
        Q.pop();

        if (dist[u] < dist[NIL])
        {

            list<int>::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = *i;

                if (dist[pairV[v]] == INF)
                {

                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }
    return (dist[NIL] != INF);
}

bool BipGraph::dfs(int u)
{
    if (u != NIL)
    {
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = *i;

            if (dist[pairV[v]] == dist[u] + 1)
            {

                if (dfs(pairV[v]) == true)
                {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }

        dist[u] = INF;
        return false;
    }
    return true;
}

BipGraph::BipGraph(int m, int n)
{
    this->m = m;
    this->n = n;
    adj = new list<int>[m + 1];
}

void BipGraph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int m, n, i, f;
    cin >> n >> m;

    vector<int> a(m);
    vector<int> b(m);
    vector<int> c(m);
    vector<int> w;

    for (i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        if (find(w.begin(), w.end(), c[i]) == w.end())
            w.push_back(c[i]);
    }

    sort(w.begin(), w.end());
    int l = 0;
    int mid = -1;
    int r = w.size();

    BipGraph g(n, n); 
    for (i = 0; i < m; i++)
        g.addEdge(a[i], b[i]);

    if (g.hopcroftKarp() != n)
    {
        cout << -1;
        return 0;
    }

    while (l <= r)
    {
        mid = (l + r) / 2;
        BipGraph g(n, n);
        for (i = 0; i < m; i++)
            if (c[i] < w[mid])
                g.addEdge(a[i], b[i]);

        if (g.hopcroftKarp() != n)
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << w[l - 1];
    return 0;
}