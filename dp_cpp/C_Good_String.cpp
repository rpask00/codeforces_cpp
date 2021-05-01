#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t, l = 0;
    string str;
    cin >> t;
    while (t--)
    {
        int dp1[10][10]{};
        int dp2[10][10]{};
        int dp3[10]{};
        
        cin >> str;

        for (int i = 0; i < str.size(); i++)
        {
            int l = str[i] - '0';
            dp3[l]++;

            for (int j = 0; j < 10; j++)
            {
                if (j == l)continue;

                if (dp1[j][l])
                {
                    dp2[j][l]++;
                    dp1[j][l] = 0;
                }
            }

            for (int j = 0; j < 10; j++)
                dp1[l][j] = 1;
        }

        int m = 0;
        l = 0;
        for (int i = 0; i < 10; i++)
        {
            l = max(l, dp3[i]);
            for (int j = 0; j < 10; j++)
                m = max(m, dp2[i][j]);
        }

        cout << min(str.size() - 2 * m, str.size() - l) << endl;
    }

    return 0;
}
