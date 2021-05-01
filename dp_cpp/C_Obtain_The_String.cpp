#include <iostream>

using namespace std;

int dp[100006][26];

int main()
{
    int h;
    cin >> h;
    while (h--)
    {
        string s;
        string t;
        cin >> s >> t;

        for (int j = 0; j < 26; j++)
            dp[s.size()][j] = -1;

        for (int i = s.size() - 1; i >= 0; i--)
        {

            for (int j = 0; j < 26; j++)
                dp[i][j] = dp[i + 1][j];

            dp[i][s[i] - 'a'] = i;
        }

        int res = 0;
        int p = 0;
        int now;
        int ch;
        while (1)
        {
            int op = p;
            ch = t[p] - 'a';
            res++;
            now = 0;

            while (now != -1)
            {
                if (s[now] == t[p])
                {
                    now++;
                    ch = t[++p] - 'a';
                }

                if (p == t.size() or now == s.size())
                    break;

                now = dp[now][ch];
            }
            
            if (op == p or p == t.size())
            {
                cout << (p == op ? -1 : res) << endl;
                break;
            }
        }
    }

    return 0;
}