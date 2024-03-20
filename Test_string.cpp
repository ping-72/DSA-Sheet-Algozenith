#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
     long long  a=((125-130)*(255*255*255*255)+325);
    multiset<int> mt={4,5 ,5, 7,11};
    for (int r:mt)
    {
        cout<<r<<" ";
    }cout<<endl;
    auto y=mt.find(7);
    cout<< &y<<endl;
    

    
}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

//int _t;cin>>_t;while(_t--) 
solve();

}