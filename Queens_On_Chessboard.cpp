#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
int n;

vector<pair<int, int>> queen_placed;
vector<string> board;
int cnt_sol =0, queen_no = 0;

bool check(int a, int b){
  if(board[a][b] == '*'){
    return false;
  }
  for(auto v:queen_placed){
    int i = v.first;
    int j = v.second;
    if( (a == i) || (b == j) || (abs(a-i) == abs(b-j))){
      return false;
    }
  }
  //cout<<a<<","<<b<<" is true."<<endl;
  return true;
}

void queen(int i){
  //base 
  if(i == n){
    if(queen_no == n){
      cnt_sol++;
      return;
    }
    else 
      return;
  }

  // checking for places
  for(int j = 0; j < n; j++){
    if(check(i,j) ){
      queen_placed.push_back({i,j});
      queen_no++;
      queen(i+1);
      queen_placed.pop_back();queen_no--;
    }
  }
}

signed main() {
  // freopen("IN", "r", stdin);
  // freopen("OUT", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  n =8;
  board.resize(n);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>board[i][j];
    }
  }

  queen(0);
  cout<<cnt_sol;


  return 0;
}