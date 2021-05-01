#include <iostream>

using namespace std;

int main()
{

    long long r = 0, n, k, A, B;

    cin >> n >> k >> A >> B;

    if (k == 1)
        r = --n * A;
    else
        while (n != 1)
        {

            if (n % k)
            {
                int h = n % k;

                if (h == n)
                    h--;

                r += A * h;
                n -= h;
            }
            else
            {
                if ((n - n / k) * A < B)
                    r += (n - n / k) * A;
                else
                    r += B;

                n /= k;
            }
        }

    cout << r;

    return 0;
}