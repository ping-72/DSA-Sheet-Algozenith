#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;



int n,x;
vector<ll> generate_sum_vector(vector<ll> subset){
    int s = subset.size();

    vector<ll> subseq_sum;

    for(int i = 0; i < (1<<s);i++){
        int sum = 0;
        for(int j = 0; j < s; j++){
            if((i>>j)&1)
                sum += subset[j];
        }
        subseq_sum.push_back(sum);
    }
    sort(subseq_sum.begin(),subseq_sum.end());
    return subseq_sum;
}

void solve(){
    // cout<<"calculating test_case"<<endl;
    cin>>n>>x;
    vector<ll> subsets1, subsets2, sub1, sub2;
    ll cnt = 0;
    
    subsets1.resize((n+1)/2);
    subsets2.resize(n - (n+1)/2);

    int a = 0, b = 0;
    for(int i=0;i<n;i++){
        if(i%2){
            cin>>subsets2[b++];
        }
        else
            cin>>subsets1[a++];
    }

    // for(auto v: subsets1)
    //     cout<<v<<" ";
    //     cout<<endl;
    // for(auto v: subsets2)
    //     cout<<v<<" ";
    //     cout<<endl;
    
    sub1 = generate_sum_vector(subsets1);
    sub2 = generate_sum_vector(subsets2);

    // for(auto v: sub1)
    //     cout<<v<<" ";
    //     cout<<endl;
    // for(auto v: sub2)
    //     cout<<v<<" ";
    //     cout<<endl;

    for(auto v:sub1){
        if(v <= x){
            cnt += upper_bound(sub2.begin(), sub2.end(), (x-v)) - sub2.begin();
        }
    }
    cout<<cnt<<endl;


}

signed main() {
  // freopen("IN", "r", stdin);
  // freopen("OUT", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
int _t;cin>>_t;while(_t--)
solve();
 
  return 0;
}