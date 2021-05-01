#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int dp[2][8]{};
    int mem[8]{};
    bool y = false;

    int l = str[0] - '0';
    dp[0][l % 8] = 1;
    mem[l % 8] = l;

    if (dp[0][0])
    {
        cout << "YES" << endl;
        cout << l << endl;
        return 0;
    }

    for (int i = 1; i < str.size(); i++)
    {
        l = str[i] - '0';
        dp[i % 2][l % 8] = 1;
        if (!mem[l % 8])
            mem[l % 8] = l;
        for (int j = 0; j < 8; j++)
        {
            if (dp[!(i % 2)][j])
            {
                int mod = (j * 10 + l) % 8;
                dp[i % 2][j] = 1;
                dp[i % 2][mod] = 1;
                if (!mem[mod])
                    mem[mod] = 10 * mem[j] + l;
            }
        }

        if (dp[i % 2][0])
        {
            cout << "YES" << endl;
            cout << mem[0];
            y = true;
            break;
        }
    }

    if (!y)
        cout << "NO" << endl;

    return 0;
}