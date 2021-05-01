#include <iostream>

using namespace std;

int main()
{

    int m, s;
    cin >> m >> s;
    int min[101];
    int max[101];
    for (int i = 0; i < m; i++){min[i] = 0;max[i] = 0;}
    if(s){min[0] = 1; max[0] = 1;}

    if (--s < 0 and m-1)
    {
        printf("-1 -1");
        return 0;
    }

    int xi = 0;
    int ni = m - 1;

    for (int i = 0; i < s; i++)
    {
        if (min[ni] == 9)
        {
            ni--;
            if (ni < 0)
            {
                printf("-1 -1");
                return 0;
            }
        }

        if (max[xi] == 9)
        {
            xi++;
            if (ni == m and s-i-1)
            {
                printf("-1 -1");
                return 0;
            }
        }

        min[ni]++;
        max[xi]++;
    }

    for (int i = 0; i < m; i++)cout << min[i];
    cout << " ";
    for (int i = 0; i < m; i++) cout << max[i];

    return 0;
}