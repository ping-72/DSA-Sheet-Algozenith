#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100010];
long long tree[4 * 100010]; // to build a 1-indexed segment tree

void build(int index, int l, int r)
{ // By the given arr you need to build the tree from index 0 to n-1
    if (l == r)
    {
        tree[index] = (arr[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(index * 2, l, mid);
    build(index * 2 + 1, mid + 1, r);
    tree[index] = max(tree[2 * index], tree[2 * index + 1]);
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
    tree[index] = max(tree[2 * index], tree[2 * index + 1]);
}

int query(int index, int l, int r, int no)
{
    if (tree[index] < no)
    {
        return INT_MAX;
    }
    if (l == r)
    {
        update(1, 0, n - 1, l, arr[l] - no);
        return l + 1;
    }
    int mid = (l + r) / 2;
    if (tree[2 * index] >= no)
    {
        return query(2 * index, l, mid, no);
    }
    else
    {
        return query(2 * index + 1, mid + 1, r, no);
    }
}

void solve()
{
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    build(1, 0, n - 1); // build a 1-indexed segment tree

    while (q--)
    {
        int ch;
        cin >> ch;
        int ans = query(1, 0, n - 1, ch);
        if (ans == INT_MAX)
            cout << 0 << " ";
        else
            cout << ans << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
