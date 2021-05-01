#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    double ax, ay, bx, by, tx, ty, n;
    double x, y;
    cin >> ax >> ay >> bx >> by >> tx >> ty >> n;

    double res = 0;
    double diff[2][2]{};
    int ind[] = {-2, -2};
    diff[0][0] = -1e18;
    diff[1][0] = -1e18;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;

        double d = sqrt(abs(tx - x) * abs(tx - x) + abs(ty - y) * abs(ty - y));
        double da = sqrt(abs(ax - x) * abs(ax - x) + abs(ay - y) * abs(ay - y));
        double db = sqrt(abs(bx - x) * abs(bx - x) + abs(by - y) * abs(by - y));

        if (d - da > diff[0][0])
        {
            diff[0][1] = max(diff[0][0], 0.0d);
            diff[0][0] = d - da;
            ind[0] = i;
        }
        else if (d - da > diff[0][1])
        {
            diff[0][1] = d - da;
        }

        if (d - db > diff[1][0])
        {
            diff[1][1] = max(diff[1][0], 0.0d);
            diff[1][0] = d - db;
            ind[1] = i;
        }
        else if (d - db > diff[1][1])
        {
            diff[1][1] = d - db;
        }

        res += 2 * d;
    }
    double del;
    if (diff[0][0] < 0 or diff[1][0] < 0)
        del = max(diff[0][0], diff[1][0]);
    else
        del = ind[0] != ind[1] ? diff[0][0] + diff[1][0] : max(diff[0][0] + diff[1][1], diff[0][1] + diff[1][0]);

    cout.precision(14);
    cout << res - del;
    // printf("%lf \n", res - del);
    return 0;
}