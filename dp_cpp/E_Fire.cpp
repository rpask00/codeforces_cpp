#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, x, y, li;
    int t[103]{};
    int p[103]{};
    vector<int> path[2005];
    long long dp[2004]{}, ans = 0;
    vector<pair<int, int>> dd;
    scanf("%i", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%i %i %i", &t[i], &x, &p[i]);
        dd.push_back(make_pair(x, i));
    }

    sort(dd.begin(), dd.begin() + n);

    for (auto d : dd)
    {
        int j = d.second;
        int f = d.first;

        for (int i = f - 1; i >= t[j]; i--)
        {

            if (dp[i - t[j]] + p[j] > dp[i])
            {
                dp[i] = dp[i - t[j]] + p[j];

                path[i] = path[i - t[j]];
                path[i].push_back(j + 1);

                if (dp[i] > ans)
                {
                    ans = dp[i];
                    li = i;
                }
            }
        }
    }

    printf("%lld \n", ans);
    printf("%i \n", path[li].size());
    for (int pp : path[li])
        printf("%i ", pp);


    return 0;
}