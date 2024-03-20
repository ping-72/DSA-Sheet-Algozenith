class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> arr_a, arr_b, ans;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == a[0]){
                int l = i;
                while(l-i < a.size() && s[l] ==a[l-i]){
                    l++;
                }
                if(l-i == a.size() ) arr_a.push_back(i);
            }
            if(s[i] == b[0]){
                int l = i;
                while(l-i < b.size() && s[l] == b[l-i]){
                    l++;
                }
                if(l-i == b.size() ) arr_b.push_back(i);
            }
        }

        sort(arr_a.begin(), arr_a.end());
        sort(arr_b.begin(), arr_b.end());

        for(auto i:arr_a){
            for(auto j:arr_b){
                if(abs(i-j) <= k){
                    ans.push_back(j);
                    ans.push_back(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};