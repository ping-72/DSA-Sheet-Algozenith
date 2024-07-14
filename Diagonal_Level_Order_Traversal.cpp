
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> getDiagonalLevelorderTraversal(Node *root)
{
    // Complete the function.
    queue<pair<Node *, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        auto node = it.first;
        auto x = it.second.first;
        auto y = it.second.second;
    }
}

Node *getBinaryTree(vector<int> &num, int *ind)
{
    if (num[*ind] == -1)
        return NULL;
    Node *node = new Node(num[*ind]);
    (*ind)++;
    node->left = getBinaryTree(num, ind);
    (*ind)++;
    node->right = getBinaryTree(num, ind);
    return node;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        assert(n <= 1000000);
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int ind = 0;
        Node *tree = getBinaryTree(arr, &ind);
        vector<vector<int>> ans = getDiagonalLevelorderTraversal(tree);
        for (auto u : ans)
        {
            for (auto v : u)
            {
                cout << v << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}
