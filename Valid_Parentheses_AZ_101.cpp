#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
    string s; int count=0;
    cin>>s; int extra=0;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(' ){extra++;}
        //if(strcmp(&s[i], "(")== 0){extra++;}
        if(s[i] == ')' ){
            extra--;}
            if(extra<0){
                count++;
                extra++;}
        
        
    }
    count=count+extra;
    cout<<count<<endl;
    
}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}