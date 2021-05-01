#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;
int vis[300001];
int parent[300001];
int i, j, p, x, y, f, a, b;
int n, m, d, k;
set <int> trm;
queue<int> q;

int main() {
	cin >> n >> k >> d;
	vector<vector<tuple<int, int>>> adj(n + 1);
	for (i = 0; i < k; i++) {
		cin >> p;  
		vis[p] = 1;
	}

	for (i = 0; i <= n; i++) {
		if(vis[i])
			q.push(i);
	}

	for (i = 1; i < n; i++) {
		cin >> a >> b;
		adj[a].push_back(make_tuple(b, i));
		adj[b].push_back(make_tuple(a, i));
	}

	while (not q.empty()) {
		int top = q.front();
		q.pop();

		for (tuple<int,int> nx : adj[top]) {
			int nxt = get<0>(nx);
			int nxi = get<1>(nx);
			
			if (nxt == parent[top]) continue;
			else if (not vis[nxt])q.push(nxt), vis[nxt] = 1, parent[nxt] = top;
			else trm.insert(nxi);
		}

	}
	
	cout << trm.size() << endl;
	for (int t : trm)
		cout << t << " ";
	
}
