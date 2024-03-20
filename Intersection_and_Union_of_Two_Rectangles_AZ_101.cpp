#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
    int x1,x2,x3,x4,y1,y2,y3,y4;
    long long area1,area2,ar_same;
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;
    area1=(x2-x1)*(y2-y1);
    area2=(y4-y3)*(x4-x3);

    if (max(x1,x3)<min(x2,x4) && max(y1,y3)<min(y2,y4))
    {
        ar_same=((max(x1,x3)-min(x2,x4))*(max(y1,y3)-min(y2,y4)));
        cout<<ar_same<<" "<<(area1+area2-ar_same)<<endl;}

        else
        cout<<"0 "<<area1+area2<<endl;
    
//O(1)
//memory- O(n)

}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}