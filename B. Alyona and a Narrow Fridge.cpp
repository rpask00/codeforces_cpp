#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;
int i, j, x;
// set<int> st;
// queue<int> que;
// vector<int> vec;
// tuple<int, int> tpl;

int main()
{
    int n, h;
    cin >> n >> h;
    int arr[1001];
    // vector<vector<tuple<int, int>>> adj(n + 1);

    for (i = 0; i < n; i++)
    {
        cin >> x;
        arr[x] = 1;
    }

    cout << n << endl;
    for (int t : arr)
        cout << t << " ";
}
