class Solution {
public:

vector<vector<int>> result;

void genAllSubsets(vector<int>& arr, vector<int>& ans, int i) {
//vector<int>& ans : Stores the subset we are currently building
    
    if(i == arr.size()) {
     result.push_back(ans);
     return;
    }

    ans.push_back(arr[i]);
    genAllSubsets(arr, ans, i + 1);

    ans.pop_back();
    genAllSubsets(arr, ans, i + 1);

}
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> ans;
        genAllSubsets(nums, ans, 0);
        return result;
        
    }
};
