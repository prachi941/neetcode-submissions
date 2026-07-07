class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

        set<vector<int>> uniqueTriplets;

        for(int i = 0; i < n; i++){
            int tar = -nums[i];

            set<int> s;

            for(int j = i + 1; j < n; j++){
                int third = tar - nums[j];

                if(s.find(third) != s.end()){
                    vector<int> trp = {nums[i], nums[j], third};
                    sort(trp.begin(), trp.end());
                    uniqueTriplets.insert(trp);
                }
                s.insert(nums[j]);
            }


        }

        vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
        return ans;
    }
};
