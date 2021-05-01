#include <iostream>
#include <string>

using namespace std;

int main()
{

    int n;
    string s;
    int dp[2][2]{};
    cin >> s;

    int i = 1;
    for (char c : s)
    {

        if (c < 91)
        {
            dp[0][i % 2] = dp[0][(i + 1) % 2];
            dp[1][i % 2] = min(dp[0][(i + 1) % 2], dp[1][(i + 1) % 2]) + 1;
        }
        else
        {
            dp[0][i % 2] = dp[0][(i + 1) % 2] + 1;
            dp[1][i % 2] = min(dp[0][(i + 1) % 2], dp[1][(i + 1) % 2]);
        }

        i++;
    }

    printf("%i \n", min(dp[1][(i + 1) % 2], dp[0][(i + 1) % 2]));

    return 0;
}