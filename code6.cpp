#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
    int s1,e1,s2,e2,Range;
    cin>>s1>>e1>>s2>>e2;
    
    if (s1==s2 && e1==e2)
    {
        cout<<"Range= "<<s1<<" to "<<e1<<endl;
    }
    
    
    else if (s1<=s2 && s2<e1 && e2>=e1)
    {
        cout<<"Range = "<<s2<<" to "<<e1<<endl;

    }
    else if (s2<=s1 && s1<e2 && e1>=e2)
    {
        swap(s1,s2);swap(e1,e2);
        cout<<"Range = "<<s2<<" to "<<e1<<endl;

    }
    else if(s1>s2 && e1<e2){
        cout<<"Range = "<<s1<<" to "<<e1<<endl;
    }
    else if(s1<s2 && e1>e2){
        cout<<"Range = "<<s2<<" to "<<e2<<endl;
    }
    else{cout<<"-1";}
    

}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

//int _t;cin>>_t;while(_t--) 
solve();

}