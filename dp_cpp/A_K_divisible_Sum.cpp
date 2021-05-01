#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    int i, j, n, m, x, y, t, k;

    cin >> t;
    while (t--)
    {

        cin >> n >> k;
        if (n % k == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            m = ceil((float)n / (float)k);
            cout << k * m / n + (k % n ? 1 : 0) << endl;
        }
    }

    return 0;
}