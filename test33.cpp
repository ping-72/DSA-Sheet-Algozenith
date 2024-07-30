#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll mod = 1e9+7;
#define endl '\n'


void solve(){
   // #S -> O()
   // #T -> O()
   int n;
   cin>>n;
   ll sum = 0;
   map<int, int> mp, mp2;
   vector<int> arr(n);
   for(int i=0; i<n;i++){
    cin>>arr[i];
    sum += arr[i];
   }

   int maxx = 0;
   for(int i=0; i<n;i++){
        mp[arr[i]]++;
        if(mp[arr[i]] >=2){
            maxx = max(maxx, arr[i]);
            arr[i] = maxx;
        }
        else{
            arr[i] = maxx;
        }
   }
   mp.clear();
   for(int i=0; i<n;i++){
    if(arr[i]) mp[arr[i]]++;
   }

   while(!mp.empty()){
    int lar = 0;
    auto sz = mp.size();
    map<int, int> mp2;
    if(sz>1){
        // int i=0;
        for(auto it= mp.begin(); it!=mp.end(); it++){
            // auto it = mp.begin();
            int a = it->first;
            int b = it->second;
            
            sum += 1LL *a*b;

            if(b>1){
                lar = max(lar, a);

                if(it == prev(mp.end())){
                    // end wala hai
                    mp2[a] = b-1;
                }
                // end wala nahi hai toh pura rahna chahiye
                else {mp2[a] = b;}
            }
            else{
                if(lar){
                    if(it != prev(mp.end())) mp2[lar]++;
                }
            }
        }
        // cout<<"Ended size"<<endl;
    }
    else if(sz == 1){
        // cout<<"Size is one"<<endl;
        auto it = mp.begin();
            int a = it->first;
            int b = it->second;
        sum += ((1LL*b*(b+1))/2)*a;
    }
    mp.clear();
    mp = mp2;
   }

   cout<<sum<<endl;

   
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll _t; cin>>_t; while(_t--)
    solve(); return 0;
}