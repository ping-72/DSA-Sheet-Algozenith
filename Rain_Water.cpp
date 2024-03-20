
#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
    IOS
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        int pre[n], suff[n];
        pre[0]=a[0];
        suff[n-1]=a[n-1];
        for (int i = 1; i < n; ++i) {
            pre[i]=max(pre[i-1], a[i]);
        }
        for (int i = n-2; i >= 0; --i) {
            suff[i]=max(suff[i+1], a[i]);
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans+=min(pre[i], suff[i]) - a[i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}