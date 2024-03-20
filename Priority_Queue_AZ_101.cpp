#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
        int Q;
        cin >> Q;

        priority_queue<int> pq; // Min-Heap

        while (Q--) {
            string query;
            cin >> query;

            if (query == "add") {
                int x;
                cin >> x;
                pq.push(x);
                // cout<<"at the top is ->"<<pq.top()<<endl; // To make it a min-heap, negate the element
            } 
            else if (query == "remove") {
                if (!pq.empty()) {
                    pq.pop(); // Remove the top element
                }
            } else if (query == "print") {
                if (!pq.empty()) {
                    cout << pq.top() << endl; // Negate the top element to get the actual value
                } else {
                    cout << "0" << endl; // Priority queue is empty, print 0
                }
            }
        }
    return;

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