#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;
int i, j, x;
const int maxn = 100;
int gym[maxn + 1];
int test[maxn + 1];
int dpg[maxn + 1];
int dpt[maxn + 1];

int main()
{
    int n;
    cin >> n;
    // vector<vector<tuple<int, int>>> adj(n + 1);

    for (i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        switch (p)
        {
        case 0:
            gym[i] = 0;
            test[i] = 0;
            break;

        case 1:
            gym[i] = 0;
            test[i] = 1;
            break;

        case 2:
            gym[i] = 1;
            test[i] = 0;
            break;

        case 3:
            gym[i] = 1;
            test[i] = 1;
            break;
        }
    }

    int res = !(gym[0] or test[0]);
    if (not gym[0] and not test[0])
        int prev = 0;
    else if (gym[0] and not test[0])
        int prev = 1;
    else if (not gym[0] and test[0])
        int prev = 2;
    else if ( gym[0] and  test[0])
        int prev = 3;

    for (i = 1; i < n; i++)
    {
        if (not gym[i] and not test[i])
            res++;

        else if (gym[i] and not test[i])
            res++;

        else if (not gym[i] and test[i] and not gym[i - 1] and test[i - 1])
            res++;
    }

    cout << res;
}