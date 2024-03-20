#include <bits/stdc++.h>
using namespace std;

class FindPairswithSum
{
public:
    
    FindPairswithSum(vector<int> &A, vector<int> &B)
    {
        
    }

    void add(int index, int val)
    {
        B[index] = val;
    }

    int count(int total)
    {
        vector<int> a,b;
        int cnt = 0;
        a = A; b= B;
        sort(b.begin(), b.end());
        for(int i=0;i<a.size();i++){
            if()
            if(lower_bound(b.begin(), b.end(), a[i]))
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> A(n), B(m);

    for (auto &i : A)
    {
        cin >> i;
    }

    for (auto &i : B)
    {
        cin >> i;
    }

    FindPairswithSum *obj = new FindPairswithSum(A, B);

    for (int i = 0; i < q; i++)
    {
        string op;
        cin >> op;
        if (op == "add")
        {
            int index, val;
            cin >> index >> val;
            obj->add(index, val);
        }
        else
        {
            int total;
            cin >> total;
            cout << obj->count(total) << '\n';
        }
    }

    return 0;
}