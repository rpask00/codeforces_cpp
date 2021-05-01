#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

    vector<string> s;
    int i, j, n, m, x, y;
    string z;
    int arr[100000];
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (i = 0; i < n; i++)
    {
        cin >> z;
        s.push_back(z);
    }

    for (i = 0; i < n; i++)
        cout << s[i] << endl;


    

    return 0;
}