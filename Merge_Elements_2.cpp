#include <bits/stdc++.h>
using namespace std;

#define N 401

// Function to return the minimum merge cost
int minMergeCost(int *arr, int n)
{
    // DP table
    int dp[N][N] = {0};

    // Calculating the cumulative sum of elements
    int prefixSum[N] = {0};
    for (int i = 1; i <= n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];

    // Filling the DP table diagonally
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                // Calculate the cost of merging the two
                // subarrays
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + prefixSum[j] - prefixSum[i - 1]);
            }
        }
    }

    // Returning the minimum merge cost
    return dp[1][n];
}

// Driver code
int main()
{
    int arr[] = {1, 3, 7};
    int n = sizeof(arr) / sizeof(int);

    cout << minMergeCost(arr, n);

    return 0;
}
