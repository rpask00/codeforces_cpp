#include <iostream>

using namespace std;

int main()
{

    int n, m, k, x, l, r;
    scanf("%i %i", &m, &n);
    int arr[100004]{};
    int lg[100004]{};
    int g[100004]{};

    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
        {
            scanf("%i", &x);
            if (x >= arr[i])
                g[i]++;
            else
                g[i] = 1;

            lg[j] = max(lg[j], g[i]);
            arr[i] = x;
        }

    scanf("%i", &k);

    for (int i = 0; i < k; i++)
    {
        scanf("%i %i", &l, &r);
        if (lg[r - 1] >= r - l + 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}