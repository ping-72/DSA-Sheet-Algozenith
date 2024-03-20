
#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

int n, k;
string s; // PRS
int dp[1001][1001][3], a[1001];
int rec(int i, int cnt, int p) {
    if (i == n)return 0;
    auto &ans = dp[i][cnt][p];
    if (ans != -1)return ans;
    ans = rec(i + 1, cnt, p) + (((p + 1) % 3) == a[i]);
    for (int j = 0; j < 3; j++) {
        if (j != p && cnt < k) {
            ans = max(ans, rec(i + 1, cnt + 1, j) + (((p + 1) % 3) == a[i]));
        }
    }
    return ans;
}
void solve() {
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'P')a[i] = 0;
        if (s[i] == 'R')a[i] = 1;
        if (s[i] == 'S')a[i] = 2;
    }
    memset(dp, -1, sizeof(dp));
    int cnt = 0, p = 0, ans2;
    int ans = rec(0, 0, 0);
    if (ans < rec(0, 0, 1))ans = rec(0, 0, 1), p = 1;
    if (ans < rec(0, 0, 2))ans = rec(0, 0, 2), p = 2;
    cout << ans << endl;
    assert(ans > 0);
    ans2 = ans;
    string moves;
    // getting lexicologically smallest.
    for (int i = 0; i < n; i++) {
        if (cnt + (p != 0) <= k && ans == rec(i, cnt + (p != 0), 0)) {
            if (i && p != 0)cnt++;
            p = 0;
            moves.push_back('P');
            if (a[i] == 1)ans--;
        }
        else if (cnt + (p != 1) <= k && ans == rec(i, cnt + (p != 1), 1)) {
            if (i && p != 1)cnt++;
            p = 1;
            moves.push_back('R');
            if (a[i] == 2)ans--;
        }
        else if (cnt + (p != 2) <= k && ans == rec(i, cnt + (p != 2), 2)) {
            if (i && p != 2)cnt++;
            p = 2;
            moves.push_back('S');
            if (a[i] == 0)ans--;
        }
        else {
            assert(false);
        }
    }
    cout << moves << endl;

    // verify.
    assert(moves.size() == n);
    assert(ans == 0);
    char prev = moves[0];
    int cnts = 0;
    for (int i = 0; i < n; i++) {
        if (moves[i] == 'P' && a[i] == 1)ans2--;
        if (moves[i] == 'R' && a[i] == 2)ans2--;
        if (moves[i] == 'S' && a[i] == 0)ans2--;
        if (moves[i] != prev)cnts++;
        prev = moves[i];
    }
    assert(cnts <= k);
    assert(ans2 == 0);
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}