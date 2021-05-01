#include <iostream>
#include <algorithm>

using namespace std;

long long dp[200005]{};

int main()
{
    int arr[200005]{};
    long long s = 0;
    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    sort(arr, arr + n + 1);

    for (int k = 1; k <= n; k++)
    {
        dp[k % m] += arr[k];
        s += dp[k % m];
        cout << s << ' ';
    }

    return 0;
}