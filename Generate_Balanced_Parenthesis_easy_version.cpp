#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int n;
string s;
int total_closed = 0,total_open = 0;
int cnt_Total_openBrackets = 0, cnt_Total_ClosedBrackets = 0;

void rec(int x_open, int y_closed){
    if(total_open > n/2 || x_open < y_closed || total_open < total_closed) {
        return;
    }
    // base case
    else if(total_closed == n/2){
        // s.push_back(')');
        for(auto v:s){
            cout<<v;
        }
        cout<<endl;

    // Cases (open =close)
    if(x_open == y_closed){
        total_open++;s.push_back('(');
        rec(x_open + 1, y_closed);
        total_open--; s.pop_back();
    }

    // Case 2 (x_open > y_closed)
    else if(total_open == n/2){
        total_closed++;s.push_back(')');
        rec(x_open , y_closed + 1);
        total_closed--; s.pop_back();
        }
    }

    else{
        // Opening a bracket
        total_open++;s.push_back('(');
        rec(x_open + 1, y_closed );
        total_open--; s.pop_back();

        // Closing a bracket
        total_closed++;s.push_back(')');
        rec(x_open , y_closed + 1);
        total_closed--; s.pop_back();

        
    }

    }


void solve(){
    
    cin>>n;

    
    
    total_open ++; s.push_back('(');
    rec(1,0);
    total_open--; s.pop_back();
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