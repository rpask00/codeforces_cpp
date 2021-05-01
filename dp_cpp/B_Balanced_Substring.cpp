#include <iostream>
#include <string>

using namespace std;

int main()
{

    int n;
    int b[100005]{};
    int dp[200005]{};
    string ss;
    scanf("%i", &n);
    cin >> ss;
    int r = 0;
    int i = 1;
    for (char s : ss)
    {
        b[i] = b[i - 1] + (s == '1' ? 1 : -1);
        if (b[i] == 0)
            r = i;
        i++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (dp[b[i] + n])
            continue;

        dp[b[i] + n] = i;
    }

    for (int i = 0; i <= n; i++)
    {
        if (dp[b[i] + n] == i)
            continue;

        r = max(r, i - dp[b[i] + n]);
    }

    printf("%i \n", r);

    return 0;
}