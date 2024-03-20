class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        vector<int> h_diff;
        for (int i = 1; i < height; i++)
        {
            if (heights[i] > heights[i - 1])
            {
                h_diff.push_back(heights[i] - heights[i - 1]);
            }
        }
        sort(h_diff.begin(), h_diff.end());
    }
};