#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    int n, t, x;
    int arr[100005]{};
    cin >> t;
    while (t--)
    {
        scanf("%i %i", &n, &x);
        for (int i = 0; i < n; i++)
            scanf("%i", &arr[i]);

        sort(arr, arr + n, greater<int>());

        int l = 1, r = 0;
        for (int i = 0; i < n; i++)
        {
            if (l * arr[i] >= x)
            {
                r++;
                l = 1;
            }
            else
            {
                l++;
            }
        }
        printf("%i \n", r);
    }

    return 0;
}