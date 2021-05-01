#include <iostream>
#include <string>

using namespace std;

int dp[200005][3]{};

int main()
{

    int n, r = 0;
    string s;
    cin >> s;

    if ((s[0] - '0') % 3 != 0)
    {
        dp[0][(s[0] - '0') % 3] = 1;
    }
    else
    {
        r++;
    }

    for (int i = 1; i < s.size(); i++)
    {
        int m = (s[i] - '0') % 3;

        if (m == 0)
        {
            r++;
            continue;
        }

        else if (m == 1)
        {
            if (dp[i - 1][2])
            {
                r++;
                continue;
            }

            if (dp[i - 1][1])
            {
                dp[i][2] = 1;
            }
            dp[i][1] = 1;
        }
        else
        {
            if (dp[i - 1][1])
            {
                r++;
                continue;
            }

            if (dp[i - 1][2])
            {
                dp[i][1] = 1;
            }
            dp[i][2] = 1;
        }
    }

    cout << r;
    return 0;
}