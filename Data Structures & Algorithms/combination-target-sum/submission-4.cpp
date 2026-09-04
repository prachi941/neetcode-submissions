class Solution {
public:

    vector<vector<int>> ans;
    vector<int> combination;

    void backtrack(int start, vector<int>& candidates, int target) {

        if(target == 0) {
            ans.push_back(combination);
            return;
        }

        if(target < 0) {
            return;
        }

        for(int j = start; j < candidates.size(); j++) {

            combination.push_back(candidates[j]);

            backtrack(j, candidates, target - candidates[j]);

            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        backtrack(0, candidates, target);

        return ans;
        
    }
};
