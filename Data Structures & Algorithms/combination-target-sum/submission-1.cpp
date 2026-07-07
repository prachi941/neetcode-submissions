class Solution {
public:
    void solve(vector<int>& arr, int idx, int target,
               vector<int>& combination,
               vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(combination);
            return;
        }

        if (idx == arr.size() || target < 0)
            return;

        // Include current element
        combination.push_back(arr[idx]);
        solve(arr, idx, target - arr[idx], combination, ans);

        // Backtrack
        combination.pop_back();

        // Exclude current element
        solve(arr, idx + 1, target, combination, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> combination;

        solve(candidates, 0, target, combination, ans);

        return ans;
    }
};