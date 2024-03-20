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

string s1,s2;
int dp[1005][1005];
int vis[1005][1005];

int len(int a, int b){
    int i =0;
    while(a<s1.length() && b<s2.length() && s1[a++]==s2[b++]){
        i++;
    }
    return i;
}

int rec(int i,int j){
    // i in s1 and j in s2
    // prune
    if(i>=s1.length() || j>=s2.length()){
        return 0;
    }
    // base
    if(i==s1.length() || j==s2.length()){
        return 0;
    }
    // cache
    if(vis[i][j] != -1){
        return dp[i][j];
    }
    // compute
    int cnt = 0;
    if(s1[i] == s2[j]){
        cnt = max(cnt, 1+rec(i+1,j+1));
    }
    
    rec(i+1, j);
    rec(i, j+1);

    // save and return
    vis[i][j] = 1;
    return dp[i][j]=cnt;
}

void solve(){
    memset(vis, -1, sizeof(vis));
    cin>>s1>>s2;

    int ans = 0;
    for(int i=0;i<s1.length();i++){
        for(int j=0;j<s2.length();j++){
            ans = max(ans, rec(i,j));
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll _t; cin>>_t; while(_t--)
    solve(); return 0;
}