#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;
   cin >> t;
   while(t--) {
       int n, k;
       cin >> n >> k;
       int x[n];
       int l = 0, r = 0;
       for (int i = 0; i < n; ++i) {
           cin >> x[i];
           l = max(l, x[i]);
           r += x[i];
       }
       int ans = 0;
       while(l <= r) {
           int mid = (l+r)/2;
           int cnt = 0;
           int now = 0;
           for (int i = 0; i < n; ++i) {
               if(now + x[i] <= mid) {
                   now += x[i];
               }
               else {
                   now = x[i];
                   cnt++;
               }
           }
           if(now) cnt++;
           if(cnt <= k) {
               ans = mid;
               r = mid - 1;
           }
           else {
               l = mid + 1;
           }
       }
       cout << ans << "\n";
   }
   return 0;
}