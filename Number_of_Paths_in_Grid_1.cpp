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

int grid[1005][1005];
int n,m;
int dp_save[1005][1005];
int vis[1005][1005];

ll dp(int i, int j) {
    // prune
    if(i<=0 || j<=0 || i>n || j>m || grid[i][j]) return 0;
    // base
    if(i ==1 && j==1) return 1ll;
    // save and check
    if(vis[i][j]){
        return dp_save[i][j];
    }
    // compute
    int ans = add(dp(i-1,j), dp(i,j-1), mod);
    // save and return
    vis[i][j] = 1;
    return dp_save[i][j] = ans;
}

void solve(){
    cin>>n>>m;
    // cout<<n<<m<<endl;
    //grid.resize(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>grid[i][j];
        }
    }

    cout<<dp(n,m)<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            vis[i][j] = 0;
        }
    }

    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
     ll _t; cin>>_t; while(_t--)
    solve(); return 0;
}