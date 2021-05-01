#include <iostream>
#include <string>

using namespace std;

int main()
{

    string s;
    int dp[3]{};
    cin >> s;

    dp[0] = s[0] == 'a';
    dp[1] = s[0] == 'b';
    dp[2] = s[0] == 'a';

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == 'a')
        {
            dp[2] = max(dp[2], dp[1]) + 1;
            dp[0]++;
        }
        else dp[1] = max(dp[0], dp[1]) + 1;
    }

    int r = max(dp[0], dp[1]);
    r = max(r, dp[2]);
    cout << r;

    return 0;
}
