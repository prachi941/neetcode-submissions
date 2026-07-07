class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

        set<vector<int>> uniqueTriplets;

        for(int i = 0; i < n; i++){
            int first = nums[i];
            int tar = -nums[i];

            set<int> s;

            for(int j = i + 1; j < n; j++){
                int sec = nums[j];
                int third = tar - sec;

                if(s.find(third) != s.end()){
                    vector<int> trp = {first, sec, third};
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
