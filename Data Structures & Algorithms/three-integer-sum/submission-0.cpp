class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        set<vector<int>> s;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    if(nums[i] + nums[j] + nums[k] == 0){

                        vector<int> trp = {nums[i], nums[j], nums[k]};
                        sort(trp.begin(), trp.end());

                        if(s.find(trp) == s.end()){
                            s.insert(trp);
                            ans.push_back(trp);
                        }
                    }

                }
            }

        }

        return ans;
    }
};
