#include <bits/stdc++.h>

using namespace std;

vector<long long> ss[200004];
int ind[200004];
int s[200004];
set<int> iii;
vector<pair<int, int>> siz;
vector<long long> ans;

int main()
{

    int t, n, x;
    scanf("%i", &t);

    while (t--)
    {
        ans.clear();
        siz.clear();
        scanf("%i", &n);
        iii.clear();
        for (int i = 0; i < n; i++)
        {
            ss[i + 1].clear();
            scanf("%i", &ind[i]);

            iii.insert(ind[i]);
        }

        for (int i = 0; i < n; i++)
        {
            scanf("%i", &s[i]);
        }

        for (int i = 0; i < n; i++)
        {
            ss[ind[i]].push_back(s[i]);
        }

        for (int i : iii)
        {
            sort(ss[i].begin(), ss[i].begin() + ss[i].size(), greater<int>());
            for (int j = 1; j < ss[i].size(); j++)
                ss[i][j] += ss[i][j - 1];

            siz.push_back(make_pair(ss[i].size(), i));
        }
        sort(siz.begin(), siz.begin() + siz.size());

        int maxk = siz.size() - 1;

        for (int k = siz[maxk].first; k >= 1; k--)
        {
            while (maxk >= 0 and siz[maxk].first >= k)
                maxk--;

            long long res = 0;

            for (int i = maxk + 1; i < siz.size(); i++)
            {
                /* code */
                int len = siz[i].first;
                if (len and len >= k)
                {
                    res += ss[siz[i].second][len - 1 - (len % k)];
                }
            }
            ans.push_back(res);
        }


        for (int i = ans.size() - 1; i >= 0; i--)
            printf("%lld ", ans[i]);

        for (int k = ans.size(); k < n; k++)
            printf("0 ");

        printf("\n");
    }

    return 0;
}
