#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

multiset<int> ms;
ll sum = 0;

void add(int x){
    sum += x;
    // cout<<"Adding "<<x<<" sum is "<<sum<<endl;
    ms.insert(x);
    return;
}
void remove(int x){
    if( !ms.empty() && ms.find(x) != ms.end() ){
            ms.erase(ms.find(x));
            sum -= x;
        // cout<<"Removing "<<x<<" sum is "<<sum<<endl;

        }
    return;
}
void p_min(){
    char c;
        cin>>c;
        if( ms.empty() ){
            cout<<-1<<endl;
        }
        else{
            auto it = ms.begin();
            cout<< *(it)<<endl;
        }
    return;
}
void p_max(){
    char c;
    cin>>c;
    if( ms.empty() ){
        cout<<-1<<endl;
    }
    else{
        auto it = ms.rbegin();
        cout<< *(it)<<endl;
    }
    return;
}
void p_sum(){
    char c;
        cin>>c;
        if( ms.empty() ){
            cout<< 0 <<endl;
        }
        else{
            cout<<sum<<endl;
        }
    return;
}

void solve(){
    int q;
    cin>>q;

    while(q--){
        int a;
        cin>>a;
        
        if(a == 1){
                int x;
            cin>>x;
            add(x);        
        }
        else if(a == 2){
            int x;
            cin>>x;
            remove(x);
        }
        else if(a == 3){
            p_min();
        }
        else if(a == 4){
            p_max();
        }
        else if(a == 5){
            p_sum();
        }
    }
}

signed main() {
  // freopen("IN", "r", stdin);
  // freopen("OUT", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
// int _t;cin>>_t;while(_t--)
solve();
 
  return 0;
}