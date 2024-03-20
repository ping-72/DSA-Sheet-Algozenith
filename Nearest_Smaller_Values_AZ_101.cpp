#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

stack<int> st;
map<int, int> mp;
vector<int> arr;

void left_lesser_no(int x,int i ){
    while( !st.empty() && st.top()>= x ){
        mp.erase(st.top());
        st.pop();
    }
    if(st.empty()){
        cout << "0 ";
    }
    else{
        cout<<mp[st.top()]<<" ";
    }
    st.push(x);
    mp[x] = i+1;

}



void solve(){
    int n;
    cin>>n;
    int b;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"0"<<" ";
    st.push(arr[0]);
    mp[arr[0]] = 1;

    for(int i=1; i<n; i++){
        b=i;
        left_lesser_no(arr[i],b);

    }
    cout<<endl;
    
    

while(!st.empty()){st.pop();}
mp.clear();
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