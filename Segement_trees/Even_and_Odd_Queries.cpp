#include <bits/stdc++.h>
using namespace std;

int arr[100010];
int tr[4 * 100010];

void build(int index, int l, int r)
{
    if (l == r)
    { // leaf node
        if (arr[l] % 2 == 0)
            tr[index] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(index * 2, l, mid);
    build(index * 2 + 1, mid + 1, r);
    tr[index] = tr[2 * index] + tr[2 * index + 1];
}

void update(int index, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        tr[index] = (val + 1) % 2;
        arr[l] = val;
        return;
    }
    int mid = (l + r) % 2;
    update(index * 2, l, mid, pos, val);
    update(index * 2 + 1, mid + 1, r, pos, val);
    tr[index] = tr[index * 2] + tr[index * 2 + 1];
}

int query(int index, int l, int r, int lq, int rq)
{
    if (l > rq || lq > r)
        return 0;
    if (lq <= l && rq >= r)
    {
        return tr[index];
    }
    int mid = (l + r) / 2;
    return query(index * 2, l, mid, lq, rq) + query(index * 2 + 1, mid + 1, r, lq, rq);
}

void solve()
{
    // #S -> O()
    // #T -> O()
    int n, q;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        if (c == '0')
        {
            int x, y;
            cin >> x >> y;
            update(1, 0, n - 1, x - 1, y);
        }
        if (c == '1')
        {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l - 1, r - 1) << endl;
        }
        if (c == '2')
        {
            int l, r;
            cin >> l >> r;
            cout << (r - l + 1) - query(1, 0, n - 1, l - 1, r - 1) << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // ll _t; cin>>_t; while(_t--)
    solve();
    return 0;
}