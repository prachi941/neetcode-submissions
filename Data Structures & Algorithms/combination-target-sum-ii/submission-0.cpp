class Solution {
public:
    void solve(vector<int>& candidates, int idx, int target,
               vector<int>& combination,
               vector<vector<int>>& ans) {

        // Base case
        if (target == 0) {
            ans.push_back(combination);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            // No need to continue if current number is greater than target
            if (candidates[i] > target)
                break;

            // Choose
            combination.push_back(candidates[i]);

            // Move to the next index (each element can be used only once)
            solve(candidates, i + 1, target - candidates[i], combination, ans);

            // Backtrack
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> combination;

        solve(candidates, 0, target, combination, ans);

        return ans;
    }
};