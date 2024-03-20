#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

ll no = 0;
void test(int i){
    if( (no>>i)& 1 ){// if its is on
        cout<<"1"<<endl;
    }
    else
        cout<<"0"<<endl;
}
void set1(int i){
    no = (no | (1<<i));
}
void clear(int i){
    no = (no & (~(1<<i)));
}
void flip(int i){
    no = (no ^ (1<<i));
}
void all(){
    if( __builtin_popcount(no) == 60){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
    }
}
void any(){
    if( __builtin_popcount(no) ){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
    }
}
void none(){
    if( no == 0){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
    }
}
void count(){
    cout<<__builtin_popcount(no)<<endl;
}
void val(){
    cout<<no<<endl;
}

void solve(){

    int n;
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        // cin>>s;
        // 1
        if(t==1){
            int i;
            cin>>i;
            test(i);
        }
        else if(t==2){
            int i;
            cin>>i;
            set1(i);
        }
        else if (t==3){
            int i;
            cin>>i;
            clear(i);
        }
        else if(t==4){
            int i;
            cin>>i;
            flip(i);
        }
        else if(t==5){
            all();
        }
        else if(t==6){
            any();
        }
        else if(t==7){
            none();
        }
        else if(t==8){
            count();
        }
        else if(t==9){
            val();
        }


    }


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