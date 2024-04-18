#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
#define endl '\n'
#define F first
#define S second

vector<int> v;
int n;

int secondLargest(vector<int> *arr)
{
    // returns the index of the second largest element in the array
    int first = 0, second = -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[first])
        {
            second = first;
            first = i;
        }
        else if (arr[i] < arr[first])
        {
            if (second == -1 || arr[second] < arr[i])
                second = i;
        }
    }
    return second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // #S -> O(1)
    // #T -> O(n)
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int index = secondLargest(&v);

    if (index == -1)
    {
        cout << "Only one element exists!" << endl;
    }
    else
    {
        cout << "Second largest element is: " << v[index] << endl;
    }

    return 0;
}