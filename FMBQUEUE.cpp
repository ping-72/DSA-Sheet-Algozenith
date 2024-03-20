#include <bits/stdc++.h>
using namespace std;

class FrontMiddleBackQueue
{
    vector<int> v;
public:
    FrontMiddleBackQueue()
    {// constructor
    }
    
    void pushFront(int val)
    {
        v.insert(v.begin(), val);
    }

    void pushMiddle(int val)
    {
        v.insert(v.begin()+ (v.size()/2), val);        
    }

    void pushBack(int val)
    {
        v.push_back(val);
    }

    int popFront()
    {
        if(v.empty())
            return -1;
        int it = v[0];
        v.erase(v.begin());
        return it;
    }

    int popMiddle()
    {
        if(v.empty())
            return -1;
        int it = v[(v.size() - 1)/2];
        v.erase(v.begin() + (v.size() - 1)/2);
        return it;
    }

    int popBack()
    {
        if(v.empty())
            return -1;
        int it = v[v.size()-1];
        v.pop_back();
        return it;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    FrontMiddleBackQueue *obj = new FrontMiddleBackQueue();
    for (int i = 0; i < q; i++)
    {
        string op;
        cin >> op;
        if (op == "pushFront")
        {
            int val;
            cin >> val;
            obj->pushFront(val);
        }
        else if (op == "pushMiddle")
        {
            int val;
            cin >> val;
            obj->pushMiddle(val);
        }
        else if (op == "pushBack")
        {
            int val;
            cin >> val;
            obj->pushBack(val);
        }
        else if (op == "popFront")
        {
            cout << obj->popFront() << '\n';
        }
        else if (op == "popMiddle")
        {
            cout << obj->popMiddle() << '\n';
        }
        else if (op == "popBack")
        {
            cout << obj->popBack() << '\n';
        }
    }
    return 0;
}