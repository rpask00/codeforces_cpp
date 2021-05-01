#include <iostream>

using namespace std;
int i, j, x, y,n,m;
unsigned long long row[2][100001];

int p[100001];
int c;

int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)cin >> p[i];
    row[0][0] = p[0];

    for (i = 0; i < n; i++)
    {
        cin >> c;
        x = (i + 1) % 2;
        y = i % 2;

        row[y][0] = row[x][0] + p[i];
        for (j = 1; j <= i; j++)
        {
            row[y][j] = min(
                row[x][j - 1] + c,
                row[x][j] + p[i] + j * m);
        }

        row[y][i + 1] = row[x][i] + c;
    }

    unsigned long long res = 9223372036854775806;
    for (i = 0; i <= n; i++)
        res = min(row[y][i], res);
    cout << res;
}
