class Solution {
public:
    bool checkIncre(int arr[], vector<int> &nums, int n){
        int maxno = -1;
        maxno = max(maxno, nums[0]);

        for(int i=1; i <n; i++){
            if(arr[i-1] != arr[i]){
                // check locally
                int localMin = min(INT_MAX, nums[i]); 
                for(int j=i+1;(j<n && (arr[j-1] == arr[j]));j++){
                    localMin = min(localMin, nums[j]);

                }
                if(localMin < maxno){
                    return false;
                }
            }
            maxno = max(maxno, nums[i]);
        }
        return true;
    }
    bool checkDecre(int arr[], vector<int> &nums, int n){
        int minno = INT_MAX;

        for(int i=1; i <n; i++){
            if(arr[i-1] != arr[i]){
                if(nums[i] > minno){
                    return false;
                }
            }
            minno = min(minno, nums[i]);
        }
        return true;
    }


    bool canSortArray(vector<int>& nums) {
        bool result = true;
        int n = nums.size();
        int arr[n];
        for(int i = 0; i < n; i++){
            arr[i] = __builtin_popcount(nums[i]);
        }
        return ( checkIncre(arr, nums,n));
        
    }
};