// C++ code for Maximum size square
// sub-matrix with all 1s
// (space optimized solution)
#include <bits/stdc++.h>

using namespace std;

// #define R 6
// #define C 5

int maximalSquare(vector<vector<char>> &matrix)
{
    if (matrix.empty())
    {
        return 0;
    }
    int m = matrix.size(), n = matrix[0].size(), sz = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!i || !j || matrix[i][j] == '0')
            {
                dp[i][j] = matrix[i][j] - '0';
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            sz = max(dp[i][j], sz);
        }
    }
    return sz * sz;
}

/* Driver code */
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<char>> matrix;
        matrix.resize(R);

        // Resize each inner vector
        for (int i = 0; i < R; i++)
        {
            matrix[i].resize(C);
            for (int j = 0; j < C; j++)
            {
                cin >> matrix[i][j];
            }
        }

        int ans = maximalSquare(matrix);
        cout << ans << endl;
    }
    return 0;
}
