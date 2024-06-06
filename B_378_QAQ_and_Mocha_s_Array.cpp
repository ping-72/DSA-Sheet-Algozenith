#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    vector<int> arr1;

    vector<bool> isdiv(n, true);
    int a = arr[0];
    for (int i = 0; i < n; i++)
    {
        int b = arr[i];
        if (b % a != 0)
            arr1.push_back(b);
    }

    if (arr1.empty())
    {
        cout << "Yes" << endl;
        return;
    }
    // for (auto l : arr1)cout << l << " ";cout << endl;

    // jo arr1 bana uske saare divisor ko mell karke dekhna padega ki koi ek similar aata hai ya nahi

    int n1 = arr1.size();

    for (int i = 1; arr[i] <= arr1[0]; i++)
    {
        int r = arr[i], div = n1;
        for (auto l : arr1)
        {
            if (l % r == 0)
                div--;
        }
        if (div == 0)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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