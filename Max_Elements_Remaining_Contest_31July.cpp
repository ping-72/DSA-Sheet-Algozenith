#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
multiset<int> mt;


void solve(){
  int is_Perfect=1,is_largest=0,count_unpaired=0;
  int n,k; cin>>n>>k;
  int a;
  for(int i=0;i<n;i++){
    cin>>a;
    mt.insert(a);
  }
  while(mt.size() !=0){
  a= *(mt.begin());
  // cout<<" a is -> "<<a<<endl;
  mt.erase(mt.begin());
  auto req_no= k-a;
  auto it= mt.lower_bound(req_no);
  // cout<<" it is -> "<<*it<<endl;
  

  if(it == mt.end()){
    count_unpaired++;
    is_largest =a;
    //cout<<" Current Largest is -> "<<is_largest<<endl;
    if(count_unpaired>=2){
      is_Perfect=0;
      break;
    }
  }
  else{
    mt.erase(it);
  }
}

if( is_Perfect ==1){
  cout<<is_largest<<endl;
}
else if(is_Perfect ==0){
  cout<<"-1"<<endl;
}




mt.clear();
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