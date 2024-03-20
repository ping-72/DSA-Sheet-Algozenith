#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int n;
map<int, int> mp;
vector<vector<int> > all_soln;

vector<int> current_permutation;

void rec(int level)
{
    //base case
    if(level ==n)
    {
        all_soln.push_back(current_permutation);
        return;
    }

    for( auto v:mp)
    {
        if(v.second !=0)
        {
            mp[v.first] --;
            current_permutation.push_back(v.first);
            rec(level+1);
            current_permutation.pop_back();
            mp[v.first] ++;
        }
    }
}



void solve(){
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;
    }
    rec(0);
    for(auto v:all_soln)
    {
        for(auto k:v)
        {
            cout<<k<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

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

