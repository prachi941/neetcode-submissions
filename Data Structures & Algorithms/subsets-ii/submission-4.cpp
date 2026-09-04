class Solution {
public:

    vector<vector<int>> ans;
    vector<int> subset;

    void backtrack(int start, vector<int>& nums) {

        ans.push_back(subset);

        for(int j = start; j < nums.size(); j++) {

            if(j > start && nums[j] == nums[j-1])
            continue;

            subset.push_back(nums[j]);

            backtrack(j+1, nums);

            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        backtrack(0, nums);

        return ans;
        
    }
};
