#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
    int n;
    cin>>n;
    map<string,int> mp;
    while(n--){
        string s;
        cin>>s;
        mp[s]++;
        auto it = mp.find(s);
        if(mp[s]==1){
                    cout<<"OK"<<endl;
                }
                else if(mp[s]>1){
                    cout<<s<<(it->second)-1<<endl;
                }
    }}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}