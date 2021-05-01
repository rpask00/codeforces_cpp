#include <iostream>

using namespace std;

int cnt[500005]{};
int arr[500005]{};

int main()
{
    int n;
    long long res = 0;
    long long s = 0;
    long long dp = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s += arr[i];
    }

    if (s % 3)
    {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        dp += arr[i];
        if (dp == s / 3)
            cnt[i] = 1;

        if (dp == (s / 3) * 2)
            cnt[i] = 2;
    }

    arr[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        if (cnt[i] == 2)
            arr[i] = arr[i + 1] + 1;
        else
            arr[i] = arr[i + 1];
    }

    for (int i = 0; i < n - 2; i++)
        if (cnt[i] == 1 + (s / 3 == 0))
            res += arr[i] - (s / 3 == 0);

    cout << res;

    return 0;
}