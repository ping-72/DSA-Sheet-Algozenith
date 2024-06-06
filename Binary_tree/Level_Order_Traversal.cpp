
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> currOrder(queue<Node *> &curr, bool &rtol)
{
    vector<int> ans;
    int n = curr.size();
    if (n == 0)
        return ans;
    bool decide = rtol;
    if (decide != true)
    {
        while (n--)
        {
            auto a = curr.front();
            curr.pop();
            ans.push_back(a->val);
            if (a->right != NULL)
                curr.push(a->right);
            if (a->left != NULL)
                curr.push(a->left);
        }
        rtol = !rtol;
    }
    else
    {
        while (n--)
        {
            auto a = curr.front();
            curr.pop();
            ans.push_back(a->val);
            if (a->left != NULL)
                curr.push(a->left);
            if (a->right != NULL)
                curr.push(a->right);
        }
        rtol = !rtol;
    }
    return ans;
}

vector<vector<int>> getLevelorderTraversal(Node *root)
{
    vector<vector<int>> ans;
    queue<Node *> q;
    if (root == NULL)
        return ans;
    q.push(root);
    int lvl = 0;

    while (!q.empty())
    {
        lvl++;
        int n = q.size();
        vector<int> k;
        while (n--)
        {
            auto a = q.front();
            q.pop();
            k.push_back(a->val);

            // Left to Right
            if (a->left != NULL)
                q.push(a->left);
            if (a->right != NULL)
                q.push(a->right);
        }
        if (lvl % 2 == 0)
        {
            reverse(k.begin(), k.end());
        }
        // k = currOrder(curr, rtol);
        ans.push_back(k);
    }
    return ans;
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
        vector<vector<int>> ans = getLevelorderTraversal(tree);
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
