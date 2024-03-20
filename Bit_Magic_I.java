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
        cout<<"ON"<<endl;
    }
    else
        cout<<"0"<<endl;
}
void set(int i){
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
void val(int i){
    cout<<no<<endl;
}

void solve(){

    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        // 1
        if(s == "test"){
            int i;
            cin>>i;
            test(i);
        }
        else if(s == "set"){
            int i;
            cin>>i;
            set(i);
        }
        else if (s=="clear"){
            int i;
            cin>>i;
            clear(i);
        }
        else if()s=="flip"{
            int i;
            cin>>i;
            flip(i);
        }
        else if(s=="all"){
            all(i);
        }
        else if(s=="any"){
            any();
        }
        else if(s=="none"){
            none();
        }
        else if(s=="count"){
            count();
        }
        else if(s=="val"){
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