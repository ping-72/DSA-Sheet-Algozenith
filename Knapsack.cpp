 #include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int n,Max_wt;
vector<pair<int,int>> Knapsack;
int dp[21][101];
int visited[21][101];
int ans = 0;

// value_max return kar raha hai har baar
int rec(int level, int weight){
    //prune
    if(weight > Max_wt)
        return -1e9;
    // base
    if(level == n){
        if(weight <= Max_wt)
            return 0;
        return (-1e9);
    }
    // cache

    // possibilties
    // Case 1
    if(weight + Knapsack[level].first <= Max_wt){
    int a = Knapsack[level].second + rec(level+1, weight + Knapsack[level].first);
    int b = rec(level+1, weight );
    ans =  max(a, b);
    return ans;
    }
    else{
    int b = rec(level+1, weight );
    ans = max(ans, b);
    return b;
    }
    


    //save and return
    return ans;
}

void solve(){
    cin >> n >> Max_wt;
    for(int i=0;i<21;i++){
        for(int j=0;j<101;j++)
            visited[i][j] = -1;
    }
    //Knapsack.resize(n);
    for(int i = 0; i <n; i++){
        int a,b;
        cin >> a >>b;
        Knapsack.push_back({a,b});
    }
    // for(int i = 0; i <n; i++){
    //     cout<<Knapsack[i].first << " "<<Knapsack[i].second<<endl;
    // }
    cout<<rec(0,0)<<endl;
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