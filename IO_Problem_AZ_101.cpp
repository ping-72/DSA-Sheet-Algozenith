#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

string s;
void solve(){
    string x,y,z;
    
    bool doub=0;// flag to check if we have seen space to know if we are processing M
    bool dot=0;// flag to check if we are now processing the Z part
   
    getline(cin,s);
    //we amke 3 part strings x,y,z so that N=x, M=y.z, z is the fractional part

    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]==' '){
            doub=1;
        }
        else if(s[i]=='.'){
                    dot=1;
                }
                else if(!doub){
                                    x+=s[i];
                                }
                                else if(!dot){
                                 y+=s[i];
                                 }
                                 else{
                                     z+=s[i];
                                 }
    }
    int x1 =stoll(x), y1 =stoll(y), z1 =stoll(z);// converting strings to numbers
    z1 += x1; 
    y1 += x1;
    cout<<z1<<"."<<y1<<endl;
    




}

signed main() {
  // freopen("IN", "r", stdin);
  // freopen("OUT", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int _t;cin>>_t;
  getline(cin,s);
  while(_t--)
solve();
 
  return 0;
}