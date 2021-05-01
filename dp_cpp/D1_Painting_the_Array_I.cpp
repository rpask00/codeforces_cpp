#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n, c;
    int arr[500005];

    cin >> n;

    vector<int> ar1;
    vector<int> ar2;

    int a1 = 0, a2 = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        int c = arr[i];
        if (a1 == 0 or c == ar1.back())
        {
            ar1.push_back(c);
            a1++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int c = arr[i];
        if (a2 == 0 or c == ar2.back())
        {
            ar2.push_back(c);
            a2++;
        }
    }

    cout << a1 + a2;

    return 0;
}