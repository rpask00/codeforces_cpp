#include <iostream>

using namespace std;

int main()
{

    int k, c = 1, s = 0;
    int a, p;

    cin >> p >> s;

    for (int i = 1; i < p; i++)
    {
        cin >> a;
        s += a;

        k = 1;
        for (int j = 1; j < a; j++)
        {
            k = k * (s - j) / j;
        }

        c = (c * k) % 1000000007;
    }

    cout << c;

    return 0;
}
