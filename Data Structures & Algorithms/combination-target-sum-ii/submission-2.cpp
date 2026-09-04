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

            if(j > start && candidates[j] == candidates[j-1]) 
            continue;

            if(candidates[j] > target)
            break;

            combination.push_back(candidates[j]);

            backtrack(j+1, candidates, target - candidates[j]);

            combination.pop_back();

        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        backtrack(0, candidates, target);

        return ans;
    }
};
