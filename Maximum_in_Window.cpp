/*

Solution 1:

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

signed main() {
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int A[n];

        for (int i = 0; i < n; i++)
            cin >> A[i];

        multiset<int> M;

        for (int i = 0; i < k; i++)
            M.insert(A[i]);

        for (int i = 0; i <= n - k; i++) {
            cout << *(M.rbegin()) << " ";
            M.erase(M.find(A[i]));
            if(i + k < n) M.insert(A[i + k]);
        }
        cout << "\n";
    }
    return 0;
}
*/


// Solution 2:

#include<bits/stdc++.h>
using namespace std;
#define endl '\n';
#define ll long long int
#define ld long double

const int N=100010;

int inf=1e9;
int mod=1e9+7;

void add(deque<int> &d, int x){
    while(!d.empty() && d.back()<x)
      d.pop_back();
    d.push_back(x);
    return;
}
void rem(deque<int> &d, int x){
    assert(!d.empty());
    if(d.front() == x) d.pop_front();
    return;
}

void solve(){
    int n,k,a[n];
    cin>>n>>k;
    for (int i = 0; i < n; i++)
     cin>>a[i];

    deque<int> dq;

    for (int i = 0; i < k; i++)
    {add(dq, a[i]);}
    
    for (int i = 0; i <= n-k; i++)
    {
        cout<<dq.front()<<" ";
        rem(dq, a[i]);
        if(i+k <n) add(dq, a[i+k]);
    }
    cout<<endl;
    

}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}