#include <iostream>
#include <string>

using namespace std;

int main()
{

    int n, t, a;
    string ss;
    string zz;
    int v = 0;
    int arr[300004]{};
    scanf("%i", &t);
    while (t--)
    {
        bool can = false;
        int i = 1;
        scanf("%i", &n);
        cin >> ss >> zz;
        for (char s : ss)
        {
            arr[i] = arr[i - 1];
            arr[i] += (s == '1');
            i++;
        }

        for (i = 1; i <= n; i++)
            arr[i] = (i == 2 * arr[i]);

        i = 1;
        for (int j = 2; j <= n; j += 2)
        {
            if (arr[j])
            {
                can = true;
                a = j - i + 1;
                v = 0;
                for (i; i <= j; i++)
                    v += ss[i - 1] == zz[i - 1];

                if (v and v != a)
                {
                    can = false;
                    break;
                }
            }
        }
        if (i <= n)
            for (i ; i <= n; i++)
                if (ss[i-1] != zz[i-1])
                    can = false;

        if (can or ss == zz)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
