class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int index, vector<int>& nums,
                   vector<int>& subset) {

        if(index == nums.size()) {
            result.push_back(subset);
            return;
        }

        // Include current element
        subset.push_back(nums[index]);
        backtrack(index + 1, nums, subset);

        // Backtrack
        subset.pop_back();

        // Exclude current element
        backtrack(index + 1, nums, subset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        backtrack(0, nums, subset);
        return result;
    }
};
