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

int cnt(string a, string b){
     int n1 = a.length();
     // int n2 = b.length();
     multiset<char> st;
     // sort(a.begin(), a.end());
     // sort(b.begin(), b.end());

     int ans = 0;
     for(int i=0; i<n1 ;i++){
          st.insert(a[i]);
     }
     for(int i=0; i<n1 ;i++){
          if(st.find(b[i]) != st.end()){
               st.erase(st.find(b[i]));
          }
          else{
               cnt++;
          }
     }
     return cnt;
}

void solve(){
   // #S -> O()
   // #T -> O()
   int n, q;
   cin>>n>>q;
   string a, b;
   cin>>a>>b;

   while(q--){
     int l, r;
     cin>>l>>r;
     if(r<= n){
          cout<<cnt(a.substr(l-1, r-l+1), b.substr(l-1, r-l+1));
     }
     else{
          cout<<0<<endl;
     }
   }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll _t; cin>>_t; while(_t--)
    solve(); return 0;
}