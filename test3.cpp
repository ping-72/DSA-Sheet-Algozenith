#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // #S -> O()
    // #T -> O()
    int n;
    cin >> n;
    vector<int> numP(n);
    vector<int> X(n);
    vector<int> Y(n);
    double x_mean, y_mean;
    for (int i = 0; i < n; i++)
        cin >> numP[i];
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        x_mean += X[i] * numP[i];
        ;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> Y[i];
        y_mean += Y[i] * numP[i];
    }

    x_mean = (1.0 * x_mean) / n;
    y_mean = (1.0 * y_mean) / n;

    x_mean = ceil(x_mean) - x_mean > 0.5 ? ceil(x_mean) : ceil(x_mean) - 1;
    y_mean = ceil(y_mean) - y_mean > 0.5 ? ceil(y_mean) : ceil(y_mean) - 1;

    cout << "x_mean = " << x_mean << "y_mean = " << y_mean << endl;
    long long dist = 0;
    for (int i = 0; i < n; i++)
    {
        dist += abs(x_mean - X[i]) + abs(y_mean - Y[i]);
    }
    cout << dist << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // ll _t; cin>>_t; while(_t--)
    solve();
    return 0;
}