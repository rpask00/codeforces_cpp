#include <bits/stdc++.h>

using namespace std;
unsigned int a[200005]{};
unsigned int ma[200005]{};
unsigned int b[200005]{};
unsigned int mb[200005]{};
bool del[200005]{};
vector<pair<int, int>> aa;

bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}

int main()
{
    unsigned int n, m, k, v;
    scanf("%i %i %i", &n, &m, &k);
    k++;
    m++;
    int x, s;
    scanf("%i %i", &x, &s);
    aa.push_back(make_pair(x, 0));

    for (int i = 1; i < m; i++)
    {
        scanf("%i", &v);
        aa.push_back(make_pair(v, 0));
    }
    for (int i = 1; i < m; i++)
    {
        scanf("%i", &v);
        aa[i].second = v;
    }

    sort(aa.begin(), aa.end(), sortbysec);

    int j = 0;
    for (int i = 1; i < m; i++)
    {
        if (aa[i].first >= aa[j].first)
            del[i] = true;
        else
            j = i;
    }

    j = 0;
    for (int i = 0; i < aa.size(); i++)
    {
        if (del[i])
            m--;
        else
        {
            a[j] = aa[i].first;
            ma[j] = aa[i].second;
            j++;
        }
    }

    for (int i = 1; i < k; i++)
        scanf("%i", &b[i]);

    for (int i = 1; i < k; i++)
        scanf("%i", &mb[i]);

    int l = 0;
    int r = m - 1;

    long long xx = x, nn = n;
    long long res = xx * nn;

    while (r >= 0)
    {
        while (r >= 0 and mb[l] + ma[r] > s)
            r--;

        if (r < 0)
            break;

        nn = n - b[l];
        if (nn <= 0)
        {
            res = 0;
            break;
        }

        xx = a[r];

        res = min(res, nn * xx);
        l++;
        if (l == k)
            break;
    }

    printf("%lld \n", res);

    return 0;
}