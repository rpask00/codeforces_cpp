#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, t;
    int p[4004]{};
    vector<int> ll;

    scanf("%i", &t);

    while (t--)
    {
        ll.clear();
        int c = 0, dp = 1;
        int sm[4004]{1};
        scanf("%i", &n);
        for (int i = 0; i < 2 * n; i++)
            scanf("%i", &p[i]);

        int li = 0;
        for (int i = 1; i < 2 * n; i++)
        {
            if (p[i] < p[i - 1] or p[i] < p[li])
                dp++;
            else
            {
                ll.push_back(dp);
                dp = 1;
                li = i;
            }
        }
        ll.push_back(dp);
        for (int l : ll)
        {
            for (int i = n - l; i >= 0; i--)
            {
                if (sm[i])
                    sm[i + l] = 1;
            }
            if (sm[n])
            {
                c = 1;
                break;
            }
        }

        printf("%s\n", c ? "YES" : "NO");
    }
    return 0;
}