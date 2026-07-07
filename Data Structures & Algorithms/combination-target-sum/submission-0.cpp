class Solution {
public:

    set<vector<int>> s;// created set to not include duplicate combinations

    void getAllCombinations(vector<int>& arr, int idx, int tar, vector<vector<int>>& ans, vector<int>& combin) {
        if(idx == arr.size() || tar < 0) {
            return;
        }

        if(tar == 0) {
            if(s.find(combin) == s.end()) {
                ans.push_back({combin});
                s.insert(combin);
            }

            return;
        }

        combin.push_back(arr[idx]);

        //to include a num single time
        getAllCombinations(arr, idx + 1, tar - arr[idx], ans, combin);

        //multiple times
        getAllCombinations(arr, idx, tar - arr[idx], ans, combin);

        combin.pop_back();

        //exclude
        getAllCombinations(arr, idx + 1, tar, ans, combin);

    }    
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {

        vector<vector<int>> ans;
        vector<int> combin;

        getAllCombinations(arr, 0, target, ans, combin);

        return ans;
        
    }
};
