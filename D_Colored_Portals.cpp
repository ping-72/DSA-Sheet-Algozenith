#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll mod = 1e9 + 7;
int INF = 1e9;
#define endl '\n'

bool cango(int i, int j, vector<string> &portals)
{
     if (portals[i][0] == portals[j][0] || portals[i][0] == portals[j][1] || portals[i][1] == portals[j][0] || portals[i][1] == portals[j][1])
          return true;
     return false;
}

void solve()
{
     // #S -> O()
     // #T -> O()
     int n, q;
     cin >> n >> q;

     vector<string> portals(n);
     vector<vector<int>> adj(n);

     for (int i = 0; i < n; ++i)
     {
          cin >> portals[i];
     }

     for (int i = 0; i < n; ++i)
     {
          for (int j = i + 1; j < n; ++j)
          {
               if (cango(i, j, portals))
               {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
               }
          }
     }

     vector<vector<int>> min_cost(n, vector<int>(n, INF));

     for (int start = 0; start < n; ++start)
     {
          queue<int> q;
          q.push(start);
          min_cost[start][start] = 0;

          while (!q.empty())
          {
               int city = q.front();
               q.pop();

               for (int next : adj[city])
               {
                    if (min_cost[start][next] > min_cost[start][city] + abs(city - next))
                    {
                         min_cost[start][next] = min_cost[start][city] + abs(city - next);
                         q.push(next);
                    }
               }
          }
     }

     while (q--)
     {
          int x, y;
          cin >> x >> y;

          int result = min_cost[x - 1][y - 1];
          if (result == INF)
               cout << -1 << endl;

          else
               cout << result << endl;
     }
}

int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     ll _t;
     cin >> _t;
     while (_t--)
          solve();
     return 0;
}