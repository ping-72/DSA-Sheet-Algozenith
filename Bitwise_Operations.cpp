#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    int n;
    cin>>n;
    int bit_cnt[21]={0};
    ll sum=0, answer=0;
    // taking input and counting no of bit on ith position of input
    for(int i=0; i<n; i++){
        // O(21n)
        int a;
        cin>>a;
        sum+=a;
        int cnt=0;
        while(a>0){
            bit_cnt[cnt]+=(a%2);
            cnt++;
            a=a/2;
        }
    }
    // for(int i=0; i<32 ; i++){
    //     cout<<"bits in "<<i<<"th position is "<<bit_cnt[i]<<endl;
    // }

    while(sum>=0){
    ll number=0;
    for(int i=0; i< 21; i++){ 
        //O(21 n)
        if(bit_cnt[i]>0){
            number+=(1ll<<i);
            bit_cnt[i]--;
        }
    }answer+=(number*number);
    sum-=number;}

    cout<<answer<<endl;



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