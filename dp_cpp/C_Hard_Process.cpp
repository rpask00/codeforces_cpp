#include <iostream>

using namespace std;

int arr[300005]{};
int z[300005]{};

int main()
{

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        scanf("%i", &arr[i]);
        z[i] = z[i - 1] + (arr[i] == 0);
    }

    int l = 0, r = k;

    int res = k == n ? n : 0;
    int resi = k == n ? n : 0;
    while (r != n)
    {
        if (z[r] - z[l] < k)
            r++;
        else if (z[r] - z[l] == k and arr[r + 1])
            r++;
        else
            l++;

        if (res < r - l)
        {
            res = r - l;
            resi = r;
        }
    }

    printf("%i \n", res);
    for (int i = 0; i < res; i++)
        arr[resi - i] = 1;

    for (int i = 1; i <= n; i++)
        printf("%i ", arr[i]);

    return 0;
}