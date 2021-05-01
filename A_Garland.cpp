#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int arr[100005]{};
    cin >> n;
    vector<int> odd;
    vector<int> eve;
    int ods = n / 2 + n % 2;
    int evs = n / 2;
    int a, r = 0, b, c, d, l = 0, f = 0, af = 0, i;

    for (i = 0; i < n; i++)
        scanf("%i", &arr[i]);

    while (arr[f] == 0 and f < n)
        f++, a = 3;

    if (f == n)
    {
        printf("%i \n", f > 1);
        return 0;
    }

    af = arr[f] % 2;
    if (arr[0] and arr[0] % 2)
        ods--;
    else if (arr[0])
        evs--;

    for (i = max(f, 1); i < n; i++)
    {
        if (not arr[i])
        {
            if (arr[i - 1])
                a = arr[i - 1] % 2;

            l++;
            continue;
        }

        arr[i] % 2 ? ods-- : evs--;

        if (arr[i] and not arr[i - 1])
        {
            if (arr[i] % 2 and a and a != 3)
                odd.push_back(l);
            else if (arr[i] % 2 == 0 and a == 0 and a != 3)
                eve.push_back(l);
            else if (a != 3)
                r++;

            l = 0;
            continue;
        }

        if (arr[i] % 2 != arr[i - 1] % 2)
            r++;
    }

    sort(eve.begin(), eve.end());
    sort(odd.begin(), odd.end());

    for (int e : eve)
        e <= evs ? evs -= e : r += 2;

    for (int o : odd)
        o <= ods ? ods -= o : r += 2;

    if (l and a % 2)
        l > ods ? r++ : ods -= l;

    if (l and not a % 2)
        l > evs ? r++ : evs -= l;

    if (f and af and f > ods)
        r++;
    if (f and not af and f > evs)
        r++;

    printf("%i \n", r);

    return 0;
}
