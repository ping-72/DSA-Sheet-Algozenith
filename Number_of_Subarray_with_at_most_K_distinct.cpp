#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll mod = 1e9+7;
#define endl '\n'

void solve(){
    int n,k;cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;
    

    // DS for two pointers condition checking
    int distinct = 0;
    map<int,int> freq;

    //pointers
    int head =-1, tail = 0;
    long long ans = 0;
    while(tail < n){
        // while there is a next element to take and we will not violate any consition
        // ((arr[head+1]==0) + cnt_zero <= k),
        while(head+1<n && ((freq[arr[head+1]]==0 && distinct<k) || (freq[arr[head+1]]>0 && distinct<=k))){
            head++;
            if(freq[arr[head]] == 0)
                distinct++;
            freq[arr[head]]++;
        }

        // H = O(1)
        // Debug
        // cout<<tail<<" "<<head<<endl;
        // cout<<"Distinct "<<distinct<<endl;

        // update your answer accordingly
        // cout<<"Ans added "<<(head - tail +1)<<endl;
        ans += head-tail+1;
        // A = O(1)

        // move tail ahead and remove the last element's contribution  
        if(head >= tail){// T = O(log n)
            freq[arr[tail]]--;
            if(freq[arr[tail]]==0){
                distinct--;
            }

            tail++;
            // cout<<"Tail goes= "<<tail<<", head= "<<head<<", dist= "<<distinct<<endl;
        }
        else{
            tail++;
            head = tail - 1;
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


void solve(){}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    // ll _t; cin>>_t; while(_t--)
    solve(); return 0;
}