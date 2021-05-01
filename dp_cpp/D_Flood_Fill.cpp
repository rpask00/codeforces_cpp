#include <iostream>

using namespace std;
const int N = 5005;
int dp[N][N][2]{};

int main()
{
    int c[N]{};
    int n, k, e, f;
    scanf("%i", &n);

    for (int r=1;r<=n;r++)
    {
        scanf("%i", &c[r]);
        for (int l=r-1;l>0;l--)
        {
            int a = c[l], b = c[r];
            dp[l][r][0] = min(dp[l+1][r][0]+(a!=c[l+1]),dp[l+1][r][1]+(a!=c[r]));
            dp[l][r][1] = min(dp[l][r-1][1]+(b!=c[r-1]),dp[l][r-1][0]+(b!=c[l]));
        }
    }

    printf("%i \n", min(dp[1][n][0], dp[1][n][1]));

    return 0;
}