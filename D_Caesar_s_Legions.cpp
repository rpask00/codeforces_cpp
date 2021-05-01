#include <iostream>
#include <map>

using namespace std;
int n1, n2, f, h;
map<tuple<int, int, int, int>, int> mp;

int solve(int n1, int n2, int k1, int k2)
{
    int result;

    if (mp.find(make_tuple(n1, n2, k1, k2)) != mp.end())
        return mp[make_tuple(n1, n2, k1, k2)];

    if (n1 < 0 or n2 < 0 or k1 < 0 or k2 < 0)
        result = 0;

    else if (not n1 and not n2)
        result = 1;
    else
        result = (solve(n1 - 1, n2, k1 - 1, h) + solve(n1, n2 - 1, f, k2 - 1)) % 100000000;

    mp[make_tuple(n1, n2, k1, k2)] = result;
    return result;
};

int main()
{
    cin >> n1 >> n2 >> f >> h;
    printf("%i", solve(n1, n2, f, h));
}
