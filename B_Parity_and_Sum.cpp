#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MODULO 1000000007
#define newline "\n"

void find_min_operations()
{
     int n;
     cin >> n;
     vector<int> nums(n);
     vector<int> arr(n);
     vector<int> arr1(n);
     vector<int> ar2r(n);
     for (int i = 0; i < n; i++)
     {
          cin >> nums[i];
     }

     int maxOdd = 0, maxEven = 0;
     for (int num : nums)
     {
          if (num % 2 == 1)
          {
               maxOdd = max(maxOdd, num);
          }
          else
          {
               maxEven = max(maxEven, num);
          }
     }

     bool isUniformParity = true;
     for (int i = 1; i < n; i++)
     {
          if ((nums[i] % 2) != (nums[0] % 2))
          {
               isUniformParity = false;
               break;
          }
     }

     if (isUniformParity)
     {
          cout << 0 << endl;
          return;
     }

     sort(nums.begin(), nums.end());
     int operations = 0;

     for (int &num : nums)
     {
          if (num % 2 == 0 && num < maxOdd)
          {
               num += maxOdd;
               operations++;
               maxOdd = max(maxOdd, num);
          }
     }

     isUniformParity = true;
     for (int i = 1; i < n; i++)
     {
          if ((nums[i] % 2) != (nums[0] % 2))
          {
               isUniformParity = false;
               break;
          }
     }

     if (isUniformParity)
     {
          cout << operations << endl;
          return;
     }

     auto oddIndex = find(nums.begin(), nums.end(), maxOdd) - nums.begin();
     nums[oddIndex] += maxEven;
     operations++;

     for (int num : nums)
     {
          if (num % 2 == 0)
          {
               operations++;
          }
     }

     cout << operations << endl;
}

int32_t main()
{
     ios::sync_with_stdio(false);
     cin.tie(nullptr);

     int testCases;
     cin >> testCases;
     while (testCases--)
     {
          find_min_operations();
     }
     return 0;
}
