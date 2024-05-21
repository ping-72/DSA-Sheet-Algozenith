#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;
    int yNeed = (y % 2 == 0) ? (y / 2) : ((y / 2) + 1);
    int remaining_cell = (yNeed * 15 - (y * 4));
    if (remaining_cell >= x)
    {
        cout << yNeed << endl;
        return;
    }
    x -= remaining_cell;
    cout << ((x % 15 == 0) ? x / 15 : (x / 15 + 1)) + yNeed << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}