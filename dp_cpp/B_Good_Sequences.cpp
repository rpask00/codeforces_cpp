#include <iostream>
#include <vector>
using namespace std;

void sito(vector<int> *rs)
{
    bool tab[1300]{};
    for (int i = 2; i * i <= 1100; i++)
    {
        if (!tab[i])
        {
            rs->push_back(i);
            for (int j = i * i; j <= 1100; j += i)
                tab[j] = 1;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int dp[100003]{}, x, r = 1;
    vector<int> prim;
    sito(&prim);
    for (int i = 1; i <= n; i++)
    {
        cin >> x;

        if(x==1)continue;

        int m = 0;
        vector<int> ind;
        for (int j : prim)
        {
            if (j >= x)
                break;
            if (x % j)
                continue;

            ind.push_back(j);

            m = max(m, dp[j]);
            m = max(dp[x / j], m);
        }

        for (int j : ind)
        {
            dp[j] = m + 1;
            dp[x / j] = m + 1;
        }

        dp[x] = m + 1;
        r = max(r, m + 1);
    }
    cout << r;
}