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

vector<vector<ll>> grid;
bool done[1005][1005];

ll rec(int r, int c){
    //prune
    if(r<0 || c<0){
        return -1e9;
    }
    //base
    if(r==0 && c==0){
        return grid[0][0];
    }
    //cache check
    if(done[r][c]){
        return grid[r][c];
    }
    //compute
    ll ans = -1e9;
    if(r!=0){
        ans = max(ans, rec(r-1,c)+grid[r][c]);
    }
    if(c!=0){
        ans = max(ans, rec(r,c-1)+grid[r][c]);
    }
    //save and return
    done[r][c] = 1;    
    return grid[r][c]=ans;
}

void solve(){
    int n,m;
    cin>>n>>m;
    grid.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;cin>>a;
            grid[i].push_back(a);
            done[i][j] = false;
        }
    }
    cout<<rec(n-1,m-1)<<endl;
    grid.clear();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
     ll _t; cin>>_t; while(_t--)
    solve(); return 0;
}