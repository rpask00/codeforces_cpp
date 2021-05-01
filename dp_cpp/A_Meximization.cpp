#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int n, t;
    int a[200]{};
    scanf("%i", &t);

    while (t--)
    {
        int u;
        vector<int> v;
        scanf("%i", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%i", &u);
            a[u]++;
        }

        int g = 0;
        for (int i = 0; i < 101; i++)
        {
            if (a[i])
            {
                g++;
                a[i]--;
                v.push_back(i);
            }
        }

        for (int i = 0; i < 101; i++)
        {
            for (int j = 0; j < a[i]; j++)
                v.push_back(i);

            a[i] = 0;
        }

        for (int h : v)
            printf("%i ", h);

        printf("\n");
    }

    return 0;
}
