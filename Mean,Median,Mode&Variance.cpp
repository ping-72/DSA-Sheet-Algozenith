#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

struct Data_dashboard
{
    ll sum=0;// for mean
    ll sumsq=0;// for variance
    double cnt=0;
    multiset<int> low,high;// for median
    map<int,int> mp;// for mode
    multiset<pair<int,int>> freq_ordr;

    void insert(int x){
        cnt++;
        sum+=x;sumsq+= x*x;
       
       //mode
        if(cnt && freq_ordr.find(make_pair(freq[x],x)) != freq_ordr.end()){
            freq_ordr.erase(freq_ordr.find(make_pair(freq[x],x)))
        }
         mp[x]++;
         freq_ordr.insert(make_pair(freq[x],x));

        //median
        if(low.empty()){}

    }
    void remove(int x){
        cnt--;
        sum-=x;sumsq-= x*x;

        //mode
        if(cnt && freq_ordr.find(make_pair(freq[x],x)) != freq_ordr.end()){
            freq_ordr.erase(freq_ordr.find(make_pair(freq[x],x)))
        }
         mp[x]--;
        if(mp[x]) {freq_ordr.insert(make_pair(freq[x],x));}
        
    }
    double mean(){
        if(cnt !=0){return (1.0*sum)/cnt;}
        else {return 0;}
    }
    double variance(){
        if(cnt){return sumsq/cnt - mean()*mean();}
        else {return 0;}
    }
    int mode(){
       if(cnt!=0){return freq_ordr.rbegin()->second;}
        else {return 0;}
    }
    double median(){
        if(cnt ==0){return 0;}
        else if(cnt%2){return (*low.rbegin()+*high.begin())/2.0;}
        else{return *low.begin() ;}
    }
};


void solve(){}

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