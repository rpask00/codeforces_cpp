#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    long long cnt[40]{};
    long long dp[40][40]{};
    cin >> str;
    long long m = 0;

    for (int i = 0; i < str.size(); i++)
    {
        int l = str[i] - 'a';

        for (int i = 0; i < 40; i++)
        {
            dp[l][i] += cnt[i];
            m = max(m, dp[l][i]);
        }

        cnt[l]++;
        m = max(m, cnt[l]);
    }
    cout << m;

    return 0;
}