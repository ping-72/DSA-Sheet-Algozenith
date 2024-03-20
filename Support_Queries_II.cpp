#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    int q,k,x;char c;
    ll sum=0; int r,cnt=0;
    cin>>q>>k;
    multiset<int> low,high;

    for (int i = 0; i < q; i++)
    {
        cin>>r;
        if(r==1){
            cin>>x;
            if((high.size()<k)){
                high.insert(x);// O(n log n)
                sum+=x;
                //cout<<"Adding "<<x<<" to high gives sum "<<sum<<endl;
            }
            else{
                if(x> *high.begin()){
                    high.insert(x);
                    sum+=x;
                    x= *high.begin();
                    high.erase(high.find(x));
                    sum-=x;
                    low.insert(x);
                    //cout<<"Adding "<<x<<" to high gives sum "<<sum<<endl;
                }
                else{
                    // x=*high.begin();
                    // high.erase(high.find(*high.begin()));
                    // sum-=x;
                   // cout<<"Removing "<<x<<" from high gives sum "<<sum<<endl;
                    low.insert(x);
                
                // low.insert(x);
                }
                
            }
        }
        else if(r==2){
            cin>>x;
            if((high.size()< k)){
                if(!high.empty() && high.count(x)){ //high.count(x) agar 0 hota hai toh unsigned X milta hai
                high.erase(high.find(x));
                sum-=x;
                //cout<<"After removing "<<x<<" from high, sum is "<<sum<<endl;
                }}

            else{
                if(high.count(x)){
                    high.erase(high.find(x));
                    sum-=x;
                    //cout<<"After removing "<<x<<" from high, sum is "<<sum<<endl;
                    //high se element hat gaya & ab high me k-1 elements h
                    if(!low.empty()){
                        x= *low.rbegin();
                       // cout<<"using reverse begin found X is "<<x<<endl;
                        high.insert(x);
                        sum+=x;
                        //cout<<"After adding "<<x<<" to high, from low the sum is "<<sum<<endl;
                        low.erase(low.find(x));
                    }
                }
                else if(low.count(x)){
                    low.erase(low.find(x));
                }
                
        }}

        if(r==3){
            cin>>c;
            cout<<sum<<endl;
        }
    
}}

signed main() {
  // freopen("IN", "r", stdin);
  // freopen("OUT", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //int _t;cin>>_t;while(_t--)
solve();
 
  return 0;
}