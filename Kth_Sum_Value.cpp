#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> Pair;
typedef long long ll;
vector<int> a, b;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        a.resize(n);
        b.resize(m);
        for (int i = 0; i < n; i++)
        {

            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {

            cin >> b[i];
        }
        if (n > m)
        {
            swap(n, m);
            swap(a, b);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int l = a[0] + b[0];
        int h = a[n - 1] + b[m - 1];
        int ans = l;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            int ne = 0;
            for (int i = 0; i < n; i++)
            {
                ne += upper_bound(b.begin(), b.end(), mid - a[i]) - b.begin();
            }
            if (ne >= k)
            {
                ans = mid;
                h = mid - 1;
            }
            else
                l = mid + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}