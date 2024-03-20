#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int n,k;
int depth = 0;
vector<char> q;
int cnt_open = 0;
int cnt_closed = 0;

void parenthesis(int len){
    // base case
    if(len == n){
        // printer
        bool got_dep_k = false;
        int cnt_depth = 0; 
        for(auto v:q){
            if(v == '('){
                cnt_depth++;
                if(cnt_depth == k){got_dep_k = true; break;}
                }
            else{ cnt_depth--;}
        }
        if(got_dep_k){
            for(auto v:q) {
                cout<<v;
            }
            cout<<endl;
        }
        // got_depth_k = false;
        return;
    }
    if(depth > k)
        return;
    
    

    // depth = k
    if(depth == k){
        q.push_back(')');
        depth--;
        cnt_closed++;
        parenthesis(len+1);
        
        q.pop_back();depth++;cnt_closed--;
    }
    // depth != k
    if(depth < k){

        // Option 1
        if(cnt_open < n/2){
        q.push_back('(');
        cnt_open++;
        depth++;
        parenthesis(len+1);
        q.pop_back();cnt_open--;depth--;
        }

        //Option 2
        if(cnt_open > (cnt_closed) ){
            q.push_back(')');
            cnt_closed++;
            depth--;
            parenthesis(len+1);
            q.pop_back();cnt_closed--;depth++;
        }

    }

}

void solve(){
    cin>>n>>k;
    q.push_back('(');
    depth++;
    cnt_open++;
    parenthesis(1);
}

signed main() {
  // freopen("IN", "r", stdin);
  // freopen("OUT", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
//int _t;cin>>_t;while(_t--)
solve();
 
  return 0;
}