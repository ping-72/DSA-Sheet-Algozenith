
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

bool isBst(Node *root)
{
    // Complete the function
    if (root == NULL)
        return true;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        auto a = q.front();
        q.pop();
        int value = a->val;
        if (a->left != NULL)
        {
            auto b = a->left;
            if (value <= b->val)
                return false;
            q.push(b);
        }
        if (a->right != NULL)
        {
            auto c = a->right;
            if (value >= c->val)
                return false;
            q.push(c);
        }
    }
    return true;
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
        if (isBst(tree))
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
    return 0;
}
