#include <bits/stdc++.h>
using namespace std;



class SnapshotArray
{
public:
	
    int timer;
    vector<vector<pair<int,int>>> arr;

	SnapshotArray(int length)
	{
		arr.resize(length);
        timer = 0;
	}

	void set(int index, int val)
	{
		while(!arr[index].empty() && arr[index].back().first == timer){
            arr[index].pop_back();
        }
        arr[index].push_back({timer, val});
	}

	int snap()
	{
		timer++;
        return timer-1;
	}

	int get(int index, int snap_id)
	{
		auto it = lower_bound(arr[index].begin(), arr[index].end(), make_pair(snap_id, INT_MAX));

        if(it == arr[index].begin()){
            return 0;
        }
        else{
            it--;return it->second;
        }
	}
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int Q, L;
	cin >> Q >> L;

	SnapshotArray snapshotArray(L);

	while (Q--)
	{
		string op;
		cin >> op;

		if (op == "set")
		{
			int index, val;
			cin >> index >> val;

			snapshotArray.set(index, val);
		}
		else if (op == "get")
		{
			int index, snap_id;
			cin >> index >> snap_id;

			cout << snapshotArray.get(index, snap_id) << "\n";
		}
		else if (op == "snap")
		{
			cout << snapshotArray.snap() << "\n";
		}
	}

	return 0;
}