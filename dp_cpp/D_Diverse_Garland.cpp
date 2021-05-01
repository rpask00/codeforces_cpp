#include <iostream>
#include <string>
using namespace std;
int dp[3][200006]{};

int main()
{
    int n;
    string str;
    cin >> n;
    cin >> str;

    for (int i = 1; i <= n; i++)
    {
        char color = str[i - 1];

        dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + (color != 'R' ? 1 : 0);
        dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + (color != 'G' ? 1 : 0);
        dp[2][i] = min(dp[1][i - 1], dp[0][i - 1]) + (color != 'B' ? 1 : 0);
    }

    string rgb = "RGB";
    int j, m = min(min(dp[1][n], dp[2][n]), dp[0][n]);

    if (m == dp[0][n])j = 0;
    if (m == dp[1][n])j = 1;
    if (m == dp[2][n])j = 2;

    str[n-1] = rgb[j];
    cout << m << endl;

    for (int i = n - 1; i > 0; i--)
    {
        m = min(dp[(j + 1) % 3][i], dp[(j + 2) % 3][i]);
        
        if (m == dp[0][i] and j != 0)j = 0;
        else if (m == dp[1][i] and j != 1)j = 1;
        else if (m == dp[2][i] and j != 2)j = 2;

        str[i-1] = rgb[j];
    }
    cout << str;

    return 0;
}