#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
    int n;
    long long sum=0;
    string number;
    cin>>number;
    n=number.length();
    for (int i = 0; i < n; i++)
    {sum += (int(number[i]-'0'));
    //O(n)
    }
    cout<<sum<<endl;
    

}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}