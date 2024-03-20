#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    int n;cin >> n;
    string s;cin>>s;
    vector<int> distinct_substring_for_i;
    distinct_substring_for_i.assign(27,0);
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            set<char> st;
            for(int k=i; k<=j; k++){
                st.insert(s[k]);
            }
            for(int k=1; k<=(st.size()); k++){
                distinct_substring_for_i[k] ++;
            }
        }
    }
    for(int i=1; i<=26; i++){
        cout << distinct_substring_for_i[i] << " ";
    }
    cout<<endl;
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