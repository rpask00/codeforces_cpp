#include <bits/stdc++.h>

using namespace std;

long long a[500005]{};
long long b[500005]{};
long long c[500005]{};
long long l[500005]{};
long long r[500005]{};
int res[500005]{};

int main()
{
    int n;
    vector<pair<int, int>> q;
    q.push_back(make_pair(0, 0));

    scanf("%i", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%i", &a[i]);
        b[n + 1 - i] = a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= a[i - 1])
            l[i] = l[i - 1] + a[i];
        else
        {
            while (q.back().first > a[i])
                q.pop_back();

            l[i] = l[q.back().second] + (i - q.back().second) * a[i];
        }
        q.push_back(make_pair(a[i], i));
    }

    q.clear();
    q.push_back(make_pair(0, 0));

    for (int i = 1; i <= n; i++)
    {
        if (b[i] >= b[i - 1])
            r[i] = r[i - 1] + b[i];
        else
        {
            while (q.back().first > b[i])
                q.pop_back();

            r[i] = r[q.back().second] + (i - q.back().second) * b[i];
        }

        q.push_back(make_pair(b[i], i));
    }
    long long ans = 0;
    long long mid = 0;

    for (int i = 1; i <= n; i++)
        c[i] = r[n + 1 - i];

    for (int i = 0; i <= n; i++)
    {
        if (ans <= l[i] + c[i + 1])
        {
            ans = l[i] + c[i + 1];
            mid = i;
        }
    }

    long long m = a[mid];
    for (int i = mid; i > 0; i--)
    {
        m = min(a[i], m);
        res[i] = m;
    }

    m = a[mid];
    for (int i = mid; i <= n; i++)
    {
        m = min(a[i], m);
        res[i] = m;
    }

    for (int i = 1; i <= n; i++)
        printf("%i ", res[i]);

    return 0;
}