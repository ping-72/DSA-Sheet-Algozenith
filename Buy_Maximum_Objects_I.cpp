#include<bits/stdc++.h>
using namespace std;
#define endl '\n';


// solution 1
/*
void solve(){
    int n,m;int x;int count=0;
    cin>>n>>m;
    multiset<int> mt;
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        mt.insert(x);
        }
    while( !mt.empty() || m>=0){
         auto z=mt.begin();
        m= m- z;count++;
       
        mt.erase(mt.find(z));
    }

   if(count>0)
   {cout<<count-1<<endl;}
   else
   {cout<<"0"<<endl; }


}*/

void solve(){
    int n,m;int x;
    cin>>n>>m;int count=0;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin>>x;v.push_back(x);
    }

    //O(log n)
    sort(v.begin(),v.end()); // if arr then Sort(arr,arr+n)
   //O(n)
    for(int i=0; (i<n && m>=0); i++){
        m= m- v[i];//cout<<"Now, money is--"<<m<<endl
        count++;
    }
    if(m>0){cout<<n<<endl;}
    else {cout<<count-1<<endl;}
}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}
