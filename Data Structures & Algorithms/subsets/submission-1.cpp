class Solution {
public:
vector<vector<int>> result;

void printSubsets(vector<int>& arr, vector<int>& ans, int i) {
    
    if(i == arr.size()) {
     result.push_back(ans);
     return;
    }

    ans.push_back(arr[i]);
    printSubsets(arr, ans, i + 1);

    ans.pop_back();
    printSubsets(arr, ans, i + 1);

}
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> ans;
        printSubsets(nums, ans, 0);
        return result;
        
    }
};
