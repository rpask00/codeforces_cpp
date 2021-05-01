#include <iostream>
#include <string>

using namespace std;

int main()
{

    int t;
    string ss;
    scanf("%i", &t);
    while (t--)
    {
        int n, k;
        scanf("%i %i", &n, &k);
        int arr[51]{};
        cin >> ss;
        int i = 0;
        int last = 0, l = 0;
        for (char s : ss)
        {
            arr[++i] = s == '*';
            if (s == '*')
            {
                last = i;
                l = l ? l : i;
            }
        }

        int dp[51][51];
        int r = 1;
        int ls = -100;

        for (int i = l + 1; i <= n; i++)
        {
            if (arr[i])
            {
                for (int j = k; j < (n, 2 * k); j++)
                {
                }
            }
        }

        printf("%i \n", r);
    }

    return 0;
}