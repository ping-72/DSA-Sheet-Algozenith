
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void preordertraverse(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
    {
        preordertraverse(root->left, ans);
    }
    if (root->right != NULL)
    {
        preordertraverse(root->right, ans);
    }
    ans.push_back(root->val);
}

vector<int> getPreorderTraversal(Node *root)
{
    // Complete the function
    vector<int> ans;
    if (root == NULL)
        return ans;
    preordertraverse(root, ans);
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
        vector<int> ans = getPreorderTraversal(tree);
        for (auto v : ans)
        {
            cout << v << " ";
        }
        cout << "\n";
    }
    return 0;
}
