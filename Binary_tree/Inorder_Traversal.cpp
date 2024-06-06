
#include <bits/stdc++.h>

using namespace std;

vector<int> trees;
struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void inordertraverse(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inordertraverse(root->left, ans);
    ans.push_back(root->val);
    inordertraverse(root->right, ans);
}
vector<int> getInorderTraversal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    inordertraverse(root, ans);
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int ind = 0;
        Node *tree = getBinaryTree(arr, &ind);
        vector<int> ans = getInorderTraversal(tree);
        trees.clear();
        for (auto v : ans)
        {
            cout << v << " ";
        }
        cout << "\n";
    }
    return 0;
}
