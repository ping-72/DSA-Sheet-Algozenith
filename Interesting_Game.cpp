#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

typedef struct game{
    int a;
    int b;
    ll sum;
}Game;

bool sum_comp(Game l, Game m){
    if(l.sum == m.sum)
        return l.a > m.a;
    return l.sum > m.sum;
}

void solve(){
    int n;
    cin>>n;
    vector<Game> v;
    vector<int> alice, bob;
    alice.resize(n);
    bob.resize(n);
    
    for(int i=0; i<n; i++){
        cin>>alice[i];
    }
    for(int i=0; i<n; i++){
        cin>>bob[i];
    }

    for(int i=0; i<n; i++){
        int l,m;
        l = alice[i]; m = bob[i];
        Game number;
        number.a = l; number.b = m;

        number.sum = (1ll*l) + (1ll*m);
        v.push_back(number);
    }
    sort(v.begin(),v.end(), sum_comp);

    ll alice_sum = 0, bob_sum = 0;
    int i =0;

    for(auto g:v){
        if(!i){
            alice_sum += 1ll*g.a;
            i++;
        }
        else {
            bob_sum += 1ll*g.b;
            i=0;
        }
    }

    if(alice_sum > bob_sum)
        cout<<"Alice"<<endl;
    else if(alice_sum < bob_sum)
        cout<<"Bob"<<endl;
    else
        cout<<"Tie"<<endl;
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