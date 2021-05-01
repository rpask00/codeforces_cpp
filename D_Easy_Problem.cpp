#include <iostream>
#include <string>

using namespace std;

int main()
{

    int n;
    string ss;
    int a;
    long long dp[5]{};
    cin >> n >> ss;

    for (char s : ss)
    {
        scanf("%i", &a);

        if (s == 'h')
            dp[0] += a;
        else if (s == 'a')
            dp[1] = min(dp[0], dp[1] + a);
        else if (s == 'r')
            dp[2] = min(dp[1], dp[2] + a);
        else if (s == 'd')
            dp[3] = min(dp[2], dp[3] + a);
    }

    printf("%lld \n", dp[3]);

    return 0;
}