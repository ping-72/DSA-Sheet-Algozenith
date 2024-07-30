#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll mod = 1e9+7;
#define endl '\n'
#define F first
#define S second
#define print(a)       		for(auto x : a) cout << x << " "; cout << endl
#define print_pair(a)           for(auto x : a) cout << x.F << " " << x.S << endl

ll gcd(ll a, ll b){if(a==0||b==0) return a+b; return gcd(b,a%b);}
ll lcm(ll a, ll b){return (b/gcd(a,b))*a;}

bool primecheck(ll n){
  if (n==2) return 1;if (n==1) return 0;
  for (ll i=2; i*i<=n; i++) {if (n%i == 0) return 0;}return 1;}

ll binary_exponentiation(ll a, ll b, ll mod){ll ans=1;
    while(b){if(b%2==1){
            ans=(ans*a)%mod;}
        a=(a*a)%mod;b=b/2;}
    return ans%mod;}

ll inv(ll x, ll mod){ return binary_exponentiation(x,mod-2,mod); }
ll add(ll a, ll b, ll mod){ return (mod + (a%mod + b%mod)%mod)%mod; }
ll sub(ll a, ll b, ll mod){ return (mod + (a%mod - b%mod)%mod)%mod; }
ll mul(ll a, ll b, ll mod){ return (mod + (a%mod * b%mod)%mod)%mod; }
ll div(ll a, ll b, ll mod){ return (mod + (a%mod * inv(b,mod)%mod)%mod)%mod; }

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<ll> ar(n);
    vector<ll> fr(n);
    vector<pair<ll,ll>> q(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) {
        cin >> freq[i];
        q.push_back({ar[i],fr[i]});
    }

    sort(arr.begin(), arr.end());

    ll ans = 0;
    
    for(int l = 0; l < n; l++){
        ll sum = 0;
        {
        ll ans1 = 0;
        ll b = arr[l];
            ll f = freq[l];
            if(1LL * b * f <= m){
                ans1 = max(ans1, 1LL * b * f);
                if(ans1 == m){ cout << m << endl; return; }
            } else {
                ans1 = max(ans1, m - (b - (m % b)));
                if(ans1 == m){ cout << m << endl; return; }
            }
    }
        if(l + 1 < n && abs(arr[l] - arr[l+1]) <= 1){
            ll a = arr[l];
            ll b = arr[l+1];
            ll f1 = freq[l];
            ll f2 = freq[l+1];

            if(1LL * f2 * b <= m){
                sum += 1LL * f2 * b;
                ll left = m - sum;
                if(f1 * a <= left){
                    sum += f1 * a;
                    ans = max(ans, sum);
                    if(ans == m){ cout << m << endl; return; }
                } else {
                    sum += left - (a - (left % a));
                    ans = max(ans, sum);
                    if(ans == m){ cout << m << endl; return; }
                }
            } else {
                ans = max(ans, m - (b - (m % b)));
            }
        } else {
            ll b = arr[l];
            ll f = freq[l];
            if(1LL * b * f <= m){
                ans = max(ans, 1LL * b * f);
                if(ans == m){ cout << m << endl; return; }
            } else {
                ans = max(ans, m - (b - (m % b)));
                if(ans == m){ cout << m << endl; return; }
            }
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll _t; cin >> _t; 
    while(_t--){
        solve();
    }
    return 0;
}
