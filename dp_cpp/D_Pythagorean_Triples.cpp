#include <iostream>

using namespace std;

int main()
{

    int n, t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        if (n < 5)
        {
            cout << 0 << endl;
            continue;
        }

        int l = 3;
        int rs = 3;
        int r = n / 2 + 1;
        int m = (l + r) / 2 + ((l + r) % 2);

        while (l + 2 < r)
        {
            m = (l + r) / 2 + ((l + r) % 2);
            m = m - ((m % 2) == 0);

            if ((m * m - 1) / 2 < n)
            {
                l = m;
                rs = m;
            }
            else
            {
                r = m;
                rs = l;
            }
        }

        cout << rs / 2 << endl;
    }

    return 0;
}