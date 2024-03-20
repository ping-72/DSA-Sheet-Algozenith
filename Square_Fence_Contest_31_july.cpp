#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;




void solve(){
    int n;cin>>n;
    int is_square = 0;
    ll  arr[n];
    ll sum=0,remainder=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(arr,arr+n);
    ll length_square= sum/4;
    if(sum %4 == 0){
        do{
            for(int i=0;i<(n-1);i++){
                if(remainder < 0){
                    i=n;
                }
                else if(remainder ==0){
                    remainder= length_square -arr[i];
                }
                else{remainder=remainder-arr[i];}
            }
            if(remainder==arr[n-1]){
                is_square=1;
            }
            
        }while(next_permutation(arr,arr+(n-1)));

        if(is_square ==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    else{
        cout<<"NO"<<endl;
    }
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