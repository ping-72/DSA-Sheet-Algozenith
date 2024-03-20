#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    int n,m,p;cin>>n>>m>>p;
    // count stars before begin - 1+ slash*1 + (p-1)*1 + n*1
    int cnt_total_stars = 1+ m*(p+1);
    string s;s.assign(cnt_total_stars,'*');

    // cout<<s<<endl;
    // int cnt_rows =1;
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<p; j++)
    //     {                        
    //         cout<<"*";
    //         for(int k=0; k<n; k++){
                
    //                     }
    //         cout<<endl;

    //     }
    //     cout<<s<<endl<<endl;
    // }

    for(int row=0; row<((p+1)*n)+1; row++){
      for(int column=0; column<((p+1)*m)+1; column++){

        if((column)%(p+1)==0 || (row)%(p+1)==0)
          cout<<'*';
        
        else if((column+row)%(2*p+2)== 0  )
          cout<<'/';

        else if(abs(column-row)%(2*p+2)== 0 )
          cout<<"\\";

        
        
        else 
          cout<<'.';
        
      }
      cout<<endl;
    }
cout<<endl;
s.clear();
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