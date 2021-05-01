#include <iostream>
#include <string>

using namespace std;

int main()
{

    int t;
    string ss;
    scanf("%i", &t);

    while (t--)
    {
        cin >> ss;
        int l = ss.size();
        if (l % 2)
            for (int i = 0; i < l / 2; i++)
            {
                if (ss[i] != 'a')
                {
                    
                }

                if (ss[l - i - 1] != 'a')
            }
        else
        {
        }
    }

    return 0;
}
