#include <bits/stdc++.h>
using namespace std;

int n;
int arr[200010];
long long tree[4 * 200010];

void build(int index, int l, int r)
{
    if (l == r)
    {
        tree[index] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(index * 2, l, mid);
    build(index * 2 + 1, mid + 1, r);
    tree[index] = tree[2 * index] + tree[2 * index + 1];
}

void update(int index, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r)
    {
        tree[index] = val;
        arr[l] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(index * 2, l, mid, pos, val);
    update(index * 2 + 1, mid + 1, r, pos, val);
    tree[index] = tree[2 * index] + tree[2 * index + 1];
}

long long query(int index, int l, int r, int lq, int rq)
{
    if (l > rq || lq > r)
        return 0;
    if (lq <= l && r <= rq)
        return tree[index];

    int mid = (l + r) / 2;
    return query(index * 2, l, mid, lq, rq) + query(index * 2 + 1, mid + 1, r, lq, rq);
}

void solve()
{
    int q;
    // cin >> q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    build(1, 0, n - 1);

    while (q--)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            int i, x;
            cin >> i >> x;
            update(1, 0, n - 1, i - 1, x);
        }
        else
        {
            int l;
            int r;
            cin >> l >> r;
            long long ans = query(1, 0, n - 1, l - 1, r - 1);
            cout << ans << endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}