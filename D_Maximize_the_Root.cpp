#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll mod = 1e9 + 7;

struct Node
{
  int val;
  vector<Node *> children;
  int minn;
};

Node *parent;

int find_max(Node *root)
{
  // leaf node hai toh
  if (root->children.empty())
  {
    root->minn = root->val;
    // cout << "No child, val is " << root->val << " " << root->minn << endl;

    return root->minn;
  }

  else
  {
    int member = root->children.size();
    int curr_min = 1e9;
    for (int i = 0; i < member; i++)
    {
      auto curr_node = root->children[i];
      curr_min = min(curr_min, find_max(curr_node));
    }
    // cout << "Curr min is " << curr_min << endl;

    if (root == parent)
    {
      // cout << "Found the parent with min " << curr_min << endl;
      return root->val + curr_min;
    }

    if (root->val >= curr_min)
    {
      // cout << "root->val >= curr_min " << curr_min << endl;
      ;
      root->minn = curr_min;
      return root->minn;
    }
    else
    {
      root->minn = root->val + (curr_min - root->val) / 2;
      return root->minn;
    }
  }
}

void solve()
{
  // #S -> O()
  // #T -> O()
  int n;
  cin >> n;
  vector<Node> a(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i].val;
  }

  for (int i = 2; i <= n; i++)
  {
    int k;
    cin >> k;
    a[k].children.push_back(&a[i]);
  }

  auto root = &a[1];
  parent = &a[1];
  int max = find_max(root);
  cout << max << endl;
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