class Solution {
public:

void solve(int index,
vector<int>& nums,
int target,
vector<int>& combination,
vector<vector<int>>& ans) {

if(target == 0) {
    ans.push_back(combination);
    return;
}

for(int i = index; i < nums.size(); i++) {

    if(i > index && nums[i] == nums[i - 1]) {
        continue;
    }

    if(nums[i] > target) {
        break;
    }

    combination.push_back(nums[i]);

    solve(i + 1,
    nums,
    target - nums[i],
    combination,
    ans);

    combination.pop_back();

 }

}
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> combination;

        solve(0,
            nums,
            target,
            combination,
            ans);

        return ans;
    }
};
