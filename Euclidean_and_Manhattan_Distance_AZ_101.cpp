#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;long double sum_mhn,sum2;

    //Manhattan
   sum_mhn= abs(x1-x2)+abs(y1-y2);
    //Euclidian
    double sum_euc= sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));

    cout<< fixed << setprecision(7);
    cout<<sum_euc<<" "<<sum_mhn<<endl;
    
}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}