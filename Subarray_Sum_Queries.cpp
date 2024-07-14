#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define LD long double

const int N = 200010;

int inf = 1e9;
int mod = 1e9 + 7;

// ll arr[200010];

struct ST
{
    ll maxi, lsum, rsum, sum;
    ST(ll sum = 0, ll maxi = 0, ll lsum = 0, ll rsum = 0) : sum(sum), maxi(maxi), lsum(lsum), rsum(rsum) {}
};

ST operator+(const ST &A, const ST &B)
{
    ST temp;
    temp.lsum = max(A.lsum, A.sum + B.lsum);
    temp.rsum = max(A.rsum + B.sum, B.rsum);
    temp.sum = A.sum + B.sum;
    temp.maxi = max(max(A.maxi, B.maxi), A.rsum + B.lsum);
    return temp;
}

struct segtree
{
    vector<ST> tree;
    segtree(int n = N)
    {
        tree.resize(4 * n);
    }

    void update(int node, int start, int end, int idx, ll val)
    {
        if (start == end)
        {
            ll x = max(val, 0LL);
            tree[node] = ST(val, x, x, x);
        }
        else
        {
            int mid = (start + end) >> 1;
            if (idx <= mid)
                update(2 * node, start, mid, idx, val);
            else
                update(2 * node + 1, mid + 1, end, idx, val);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    ll query()
    {
        return tree[1].maxi;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    segtree T(n);

    for (int i = 0; i < n; i++)
    {
        ll val;
        cin >> val;
        T.update(1, 0, n - 1, i, val);
    }
    // build(1, 0, n - 1);
    while (q--)
    {
        int k;
        ll x;
        cin >> k >> x;
        k--;
        T.update(1, 0, n - 1, k, x);
        cout << T.query() << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
