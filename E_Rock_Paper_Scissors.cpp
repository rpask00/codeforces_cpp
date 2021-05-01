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
    int a[3];
    int b[3];

    for (i = 0; i < 3n; i++)
    {
        cin >> x;
        arr[i] = x;
    }

    for (i = 0; i < 3n; i++)
    {
        cin >> x;
        arr[i] = x;
    }

    int mn = 0;
    mn += min(a[0],b[1]);
    mn += min(a[1],b[2]);
    mn += min(a[2],b[0]);

}
