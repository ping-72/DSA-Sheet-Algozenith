#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
int n,k;
vector<ll> factorial(n);
// vector<ll> arr;

int fact(int n){
  if(n ==1){
    factorial[1] = 1;
    factorial[0] = 1;
        return 1;
  }
  else{
    factorial[n] = n*fact(n-1);
    return (factorial[n]);
  }
}


void solve1(){
    cin>>n>>k;
    
    int arr[n];
    for(int i=0; i<n; i++){
      arr[i] = i+1;
    }

    ll total_cnt=0;
    
    do
    {
      total_cnt ++;
      if(total_cnt == k){
        for(auto v:arr){
          cout<< v<<" ";
        }
        cout<< endl;
      }
      if(total_cnt == k){
        break;
      }
    } while (next_permutation(arr,arr+n));}

    void solve2(){
      
    }

signed main() {
  // freopen("IN", "r", stdin);
  // freopen("OUT", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
//int _t;cin>>_t;while(_t--)
//solve1();
solve2();
 
  return 0;
}