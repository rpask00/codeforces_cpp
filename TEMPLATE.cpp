#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;
int vis[300001];
int i, j, x;
// set<int> st;
// queue<int> que;
// vector<int> vec;
// tuple<int, int> tpl;

int main()
{
    int n;
    cin >> n;
    int arr[300001];
    // vector<vector<tuple<int, int>>> adj(n + 1);

    for (i = 0; i < n; i++)
    {
        cin >> x;
        arr[p] = 1;
    }

    for (i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << n << endl;
    for (int t : arr)
        cout << t << " ";
}
