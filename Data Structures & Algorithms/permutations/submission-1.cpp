class Solution {
public:

    vector<vector<int>> ans;
    vector<int> permutation;
    vector<bool> used;

    void backtrack(vector<int>& nums) {

        if(permutation.size() == nums.size()) {
            ans.push_back(permutation);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            if(used[i])
            continue;

            permutation.push_back(nums[i]);
            used[i] = true;

            backtrack(nums);

            used[i] = false;
            permutation.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        used.resize(nums.size(), false);

        backtrack(nums);

        return ans;
        
    }
};
