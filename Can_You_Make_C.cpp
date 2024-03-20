#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

int gcd(int x, int y){
     // Everything divides 0
    // cout<<x<<" "<<y<<endl;
    if (x == 0)
        return y;
    if (y == 0)
        return x;
 
    // Base case
    if (x == y)
        return x;
 
    // a is greater
    if (x > y)
        return gcd(x - y, y);
    return gcd(x, y - x);
}

bool check_soln(int a,int b,int c){
        
    if(c%(gcd(a,b))==0 ){
        return true;
    }
    else return false;
    
}
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    if(check_soln(a,b,c)){cout<<"Yes"<<endl;}
    else{cout<<"No"<<endl;}


}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}