class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int index, vector<int>& subset) {
        ans.push_back(subset);

        for (int i = index; i < nums.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > index && nums[i] == nums[i - 1])
                continue;

            subset.push_back(nums[i]);
            solve(nums, i + 1, subset);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> subset;
        solve(nums, 0, subset);

        return ans;
    }
};