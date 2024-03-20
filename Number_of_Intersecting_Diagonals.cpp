#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

ll cal_mod(ll p,ll q){
    return ((p*q) % mod);

}
int bin_pow(int a, int b) {  // required since answer needs to be in modulo
  int ans = 1;
  while (b) {
    if (b % 2 == 1) ans = (ans * a) % mod;
    a = (a * a) % mod;  // since we needed to take %, we did not take a*=a;
    b /= 2;
  }
  return ans;
}

inline int mul(int a, int b) {  // preventing multiplication overflow
  return (a * b) % mod;
}



void solve(){
    ll n,ans;
    cin>>n;
    // Calcuating C( n,4) mod 1e9+7
    int answer = mul(N, N - 1);
  answer = mul(answer, N - 2);
  answer = mul(answer, N - 3);
  answer = mul(answer, bin_pow(24, mod - 2));  // O(log N)
  if (answer < 0) answer += mod;
  cout << answer % mod << endl;

}

signed main() {
  // freopen("IN", "r", stdin);
  // freopen("OUT", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
int _t;cin>>_t;while(_t--)
solve();
 
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long int fast_exp(long long int a, long long int b){
    long long result = 1, A;
    A = a;
    while(b){
        if (b % 2) result = (result * A) % mod;
        A = (A * A) % mod;
        b /= 2;
    }
    return result;
}

long long int inverse(long long int a){
    return fast_exp(a, mod - 2);
}

long long int solve(long long int N){
    long long int ans1, ans2, ans3, ans4, ans;
    ans1 = ((N - 1) * (N - 2)) % mod;
    ans2 = ((((N - 3) * (N - 2)) % mod) * inverse(2)) % mod;
    ans3 = ((((2 * N - 5) * (2 * N - 3)) % mod) * inverse(3)) % mod;
    ans4 = ((((N - 3) * (N - 2)) % mod) * inverse(4)) % mod;
    ans = ((((ans1 + ans2) % mod) - ans3 + mod) % mod * ans4) % mod;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long int T;
    cin >> T;
    long long int N;
    while(T--){
        cin >> N;
        if (N == 3) {cout << 0 << endl; continue;}
        cout << solve(N) << endl;
    }
}