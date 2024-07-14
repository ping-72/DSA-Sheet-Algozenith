#include <bits/stdc++.h>
using namespace std;

int n;
int arr[200010];
long long sgt[4 * 200010];
long long lazy[4 * 200010];

void build(int index, int l, int r)
{
    if (l == r)
    {
        sgt[index] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    sgt[index] = 0; // Initialize internal nodes as 0
}

void propagate(int index, int l, int r)
{
    if (lazy[index] != 0)
    {
        sgt[index] += lazy[index];
        if (l != r) // Not a leaf node
        {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }
        lazy[index] = 0;
    }
}

void increase(int index, int l, int r, int lq, int rq, long long x)
{
    propagate(index, l, r);

    if (lq > r || rq < l)
    {
        return; // No overlap
    }

    if (lq <= l && r <= rq)
    {
        sgt[index] += x;
        if (l != r)
        {
            lazy[2 * index] += x;
            lazy[2 * index + 1] += x;
        }
        return;
    }

    int mid = (l + r) / 2;
    increase(2 * index, l, mid, lq, rq, x);
    increase(2 * index + 1, mid + 1, r, lq, rq, x);
}

long long query(int index, int l, int r, int leaf)
{
    propagate(index, l, r);

    if (l == r)
    {
        return sgt[index];
    }

    int mid = (l + r) / 2;
    if (leaf <= mid)
    {
        return query(2 * index, l, mid, leaf);
    }
    else
    {
        return query(2 * index + 1, mid + 1, r, leaf);
    }
}

void solve()
{
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(1, 0, n - 1);
    while (q--)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            int a, b;
            long long x;
            cin >> a >> b >> x;
            increase(1, 0, n - 1, a - 1, b - 1, x);
        }
        else
        {
            int a;
            cin >> a;
            long long ans = query(1, 0, n - 1, a - 1);
            cout << ans << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
