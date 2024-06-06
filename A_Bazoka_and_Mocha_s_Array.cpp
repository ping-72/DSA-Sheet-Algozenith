#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<bool> isinc(n, true);

    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            isinc[i] = false;
            if (!isinc[i - 1])
            {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}