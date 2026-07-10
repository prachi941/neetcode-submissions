class Solution{
public:
 //t.c : O(n * n!)
 //s.c : O(n)
    void solve(vector<int>& nums,
    vector<int>& permutation,
    vector<bool>& used,
    vector<vector<int>>& ans) {

        if(permutation.size() == nums.size()) {
            ans.push_back(permutation);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            if(used[i]) {
                continue;
            }

            permutation.push_back(nums[i]);
            used[i] = true;

            solve(nums, permutation, used, ans);

            permutation.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> permutation;

        vector<bool> used(nums.size(), false);

        solve(nums, permutation, used, ans);

        return ans;
    }
};