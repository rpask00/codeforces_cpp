#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;
int vis[300001];
int i, j, x;
// set<int> st;
// queue<int> que;
// vector<int> vec;
// tuple<int, int> tpl;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> fr(n, vector<char>(m, '.'));
    vector<vector<int>> depths(n, vector<int>(m, 0));

    for (i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        j = 0;
        for (char r : row)
        {
            fr[i][j++] = r;

            if (r == 'X')
            {

                if (i && j && fr[i - 1][j] == 'X' && fr[i - 1][j - 1] == 'X' && fr[i - 1][j - 1] == 'X')
                    depths[i][j] = min(depths[i - 1][j], depths[i - 1][j - 1], depths[i - 1][j - 1]) + 1;
                else
                    depths[i - 1][j] = 1;
            }
            else
            {
            }
        }
    }

    cout << n << endl;
    for (int t : arr)
        cout << t << " ";
}
