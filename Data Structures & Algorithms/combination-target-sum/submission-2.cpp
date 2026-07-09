class Solution {
public:

    void solve(int index,
    vector<int>& nums,
    int target,
    vector<int>& combination,
    vector<vector<int>>& ans) {

        if(index == nums.size()) {

            if(target == 0) {
                ans.push_back(combination);
            }
            return;
        }

    if(nums[index] <= target) {

    combination.push_back(nums[index]);

    solve(index,
    nums,
    target - nums[index],
    combination,
    ans);

    combination.pop_back();
}

    solve(index + 1,
    nums,
    target,
    combination,
    ans);
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;

        vector<int> combination;

        solve(0, nums, target, combination, ans);

        return ans;
        
    }
};
