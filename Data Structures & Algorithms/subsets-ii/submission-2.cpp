class Solution {
public:

//sorting will be req here

    void solve(int index,
    vector<int>& nums,
    vector<int>& subset,
    vector<vector<int>>& ans) {

        ans.push_back(subset);

        for(int i = index; i < nums.size(); i++) {

            if(i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            subset.push_back(nums[i]);

            solve(i + 1, nums, subset, ans);

            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> subset;

        solve(0, nums, subset, ans);

        return ans;
        
    }
};
