#include <iostream>
#include <string>

using namespace std;

int main()
{
    int dp[100000]{1};
    string str;
    cin >> str;

    for (int i = 0; i < 2; i++)
        if (str[i] == 'm' or str[i] == 'w'){cout << 0; return 0;}

    dp[1] = str[0] == str[1] ? 2 : 1;

    for (int i = 2; i < str.size(); i++)
    {

        if (str[i] == 'w' or str[i] == 'm'){cout << 0;return 0;}

        if ((str[i] == 'u' and str[i - 1] == 'u') or (str[i] == 'n' and str[i - 1] == 'n'))
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        else
            dp[i] = dp[i - 1] % 1000000007;
    }

    cout << dp[str.size() - 1];
    return 0;
}
