#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

void diving_by_two(int x){
    while(x%2 ==0)
        x = x / 2;
}
void diving_by_five(int x){
    while(x%5 == 0)
        x = x / 5;
}

void solve(){
    int num, dino;
    cin>>num>>dino;

if(num==0){
    cout<<0<<endl;
}

// positive
else if(num * dino){
    if(num % dino == 0){
        // completely divisible
        cout<<num/dino<<endl;
    }

    else{
    // recurring or terminating

    map<int, int> m1; // Using a map to store repetation of remainder and position
    int i=0,pos;
    string s = "";
    bool flag_recurring = true;
    int num1 = num/dino;
    int a = num, b = dino;
    a = a%b;
    m1.insert({a,1});
    a = a*10;
    ++i;
    while(1){
        int x, rem;
        x = a/b;
        rem = a%b;
        if(rem == 0){
            // terminating
            s += char(x+ 48);
            break;
        }
        else if(m1.count(rem)){
            // remainder is repeated
            s += char(x+48);
            pos = m1[rem]; // position for opening parenthesis
            flag_recurring = false;
            break;
        }
        else{
            //remainder is not repeated
            m1.insert({rem,i});
            ++i;
            s += char(x+48);
            a = rem*10;
        }
    }

    if(!flag_recurring){
        cout<<num1<<"."<<s.substr(0, pos)<<"("<<s.substr(pos, s.length() - pos)<<")"<<endl;
    }
    else{
        cout<<num1<<"."<<s<<endl;
    }

    }
}

// negative
else {
        num = abs(num);
        dino = abs(dino);
        int a = num, b = dino;
     if(num % dino == 0){
        // completely divisible
        cout<<"-"<<num/dino<<endl;
    }

    else{
    // recurring or terminating

    map<int, int> m1; // Using a map to store repetation of remainder and position
    int i=0,pos;
    string s = "";
    bool flag_recurring = true;
    int num1 = num/dino;
    int a = num, b = dino;
    a = a%b;
    m1.insert({a,1});
    a = a*10;
    ++i;
    while(1){
        int x, rem;
        x = a/b;
        rem = a%b;
        if(rem == 0){
            // terminating
            s += char(x+ 48);
            break;
        }
        else if(m1.count(rem)){
            // remainder is repeated
            s += char(x+48);
            pos = m1[rem]; // position for opening parenthesis
            flag_recurring = false;
            break;
        }
        else{
            //remainder is not repeated
            m1.insert({rem,i});
            ++i;
            s += char(x+48);
            a = rem*10;
        }
    }

    if(!flag_recurring){
        cout<<"-"<<num1<<"."<<s.substr(0, pos)<<"("<<s.substr(pos, s.length() - pos)<<")"<<endl;
    }
    else{
        cout<<"-"<<num1<<"."<<s<<endl;
    }

    }

    }
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