#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{

    int n, t;
    cin >> t;
    while (t--)
    {
        string s;
        int arr[200004]{};
        int r = 0;
        cin >> n >> s;

        int j = 0;

        while (j < n and s[n - 1] == s[j])
        {
            s += s[n - 1];
            j++;
        }

        if (j == n)
        {
            cout <<(int)ceil((float)n / 3) << endl;
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            arr[i] = s[i + j] == 'R';
        }

        for (int i = 2; i < n - 1; i++)
        {
            if (arr[i - 2] == arr[i] and arr[i - 1] == arr[i] and arr[i] == arr[i + 1])
            {
                arr[i] = (arr[i] + 1) % 2;
                r++;
            }
        }

        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i - 1] == arr[i] and arr[i] == arr[i + 1])
            {
                arr[i] = (arr[i] + 1) % 2;
                r++;
            }
        }

        cout << r << endl;
    }

    return 0;
}