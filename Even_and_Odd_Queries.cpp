#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100010];
long long tree[4 * 100010]; // to build a 1-indexed sgt

void build(int index, int l, int r)
{ // By the given arr you need to build the tree from index 0 to n-1
    if (l == r)
    {
        tree[index] = (arr[l] % 2 ? 0 : 1);
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
        tree[index] = (val % 2 ? 0 : 1);
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
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> q;

    build(1, 0, n - 1); // build a 1-indexed sgt

    while (q--)
    {
        int ch;
        cin >> ch;
        if (ch == 0)
        {
            int i, x;
            // cout << "Solving Q0" << endl;
            cin >> i >> x;
            update(1, 0, n - 1, i - 1, x);
        }
        else if (ch == 1)
        {
            int l;
            // cout << "Solving Q1" << endl;
            int r;
            cin >> l >> r;
            int ans = query(1, 0, n - 1, l - 1, r - 1);
            cout << ans << endl;
        }
        else
        {
            int l;
            int r;
            // cout << "Solving Q2" << endl;
            cin >> l >> r;
            int ans = r - l + 1 - query(1, 0, n - 1, l - 1, r - 1);
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