#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{

    map<int, int> dp;
    int arr[200005];
    int index = 0;

    vector<int> res;

    int n;
    int mx = 0;
    int m = 0;
    int l = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dp[arr[i]] = dp[arr[i] - 1] + 1;
        m = dp[arr[i]];
        if (mx <  m)
        {
            mx = m;
            l = arr[i];
        }
    }

    cout << mx << endl;
    int t = l - mx + 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == t)
        {
            cout << i + 1 << ' ';
            t++;
        }
    }

    return 0;
}