#include <bits/stdc++.h>
using namespace std;

// Function to verify if a candidate value is valid
bool is_valid(int c, const vector<int> &nums, int step, vector<int> &nums2)
{
     for (int num : nums2)
     {
          int diff = c - num;
     }

     for (int num : nums)
     {
          int diff = c - num;
          int q = diff / step;
          if (q % 2 != 0)
               return false;
          if (c < num + q * step || c > num + (q + 1) * step)
          {
               return false;
          }
     }
     return true;
}

int main()
{
     ios::sync_with_stdio(false);
     cin.tie(nullptr);
     cout.tie(nullptr);

     int t;
     cin >> t;

     while (t--)
     {
          int n, k;
          cin >> n >> k;
          vector<int> a(n);
          vector<int> a2(n);
          vector<int> a3(n);

          for (int &x : a)
          {
               cin >> x;
          }

          sort(a.begin(), a.end());
          bool found = false;

          for (int i = a.back(); i <= a.back() + k; ++i)
          {
               if (is_valid(i, a, k, a2))
               {
                    cout << i << '\n';
                    found = true;
                    break;
               }
          }

          if (!found)
          {
               cout << -1 << '\n';
          }
     }
     return 0;
}
