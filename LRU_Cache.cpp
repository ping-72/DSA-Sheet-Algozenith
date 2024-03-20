#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    
    list<int> dll; // key ke liye linked list
    map<int, pair<list<int>::iterator, int>> mp;
    
    int n;
    
    LRUCache(int capacity)
    {
        //Complete function
        n = capacity;
    }
    
    void makeRecentlyUsed(int key){
        dll.erase(mp[key].first);
        
        dll.push_front(key);
        
        mp[key].first = dll.begin();// yahan pe mp[key].second nahi change kiye kyuki wo toh map me same hi rahega sirf iterator change hua hai
    }
    
    
    int get(int key)
    {
        //Complete function
        if(mp.find(key) == mp.end()){
            return -1;
        }
        
        makeRecentlyUsed(key);
        return mp[key].second ;
    }

    void put(int key, int value)
    {
        //Complete function
        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            makeRecentlyUsed(key);
        }
        else{
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }
        
        if(n < 0){
            int key_tobe_del = dll.back();
            mp.erase(key_tobe_del);
            
            dll.pop_back();
            
            n++;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q, cap;
    cin >> q >> cap;
    LRUCache *obj = new LRUCache(cap);
    for (int i = 0; i < q; i++)
    {
        string op;
        cin >> op;
        if (op == "get")
        {
            int key;
            cin >> key;
            cout << obj->get(key) << '\n';
        }
        else
        {
            int key, val;
            cin >> key >> val;
            obj->put(key, val);
        }
    }

    return 0;
}