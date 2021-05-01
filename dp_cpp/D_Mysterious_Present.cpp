#include <bits/stdc++.h>

using namespace std;

int main()
{
    int dp[5004]{}, ls[5004]{}, li = 0;
    int hh, ww, wm = 0, r = 0;
    int n, w, h;
    vector<tuple<int, int, int>> e;
    cin >> n >> w >> h;

    for (int i = 0; i < n; i++)
    {
        cin >> ww >> hh;
        if (ww <= w or hh <= h)
            continue;

        r = 1;
        wm = max(wm, ww);
        e.push_back(make_tuple(ww, hh, i));
    }
    n = e.size();
    sort(e.begin(), e.end());

    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = 1;

        if (get<0>(e[i]) == wm)
        {
            li = get<2>(e[i]);
            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (get<0>(e[i]) == get<0>(e[j]))
                continue;

            if (get<1>(e[i]) >= get<1>(e[j]))
                continue;

            if (dp[j] + 1 < dp[i])
                continue;

            ls[get<2>(e[i])] = get<2>(e[j]);
            dp[i] = dp[j] + 1;

            if (r < dp[i])
            {
                li = get<2>(e[i]);
                r = dp[i];
            }
        }
    }

    cout << r << endl;
    for (int i = 0; i < r; i++)
    {
        cout << li + 1 << ' ';
        li = ls[li];
    }

    return 0;
}