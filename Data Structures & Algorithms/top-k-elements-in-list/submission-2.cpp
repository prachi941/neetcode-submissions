class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        for(int num : nums) 
            mp[num]++;

            vector<vector<int>> bucket(nums.size() + 1);

            for(auto &it : mp) {

                bucket[it.second].push_back(it.first);

            }

            vector<int> ans;

            for(int i = bucket.size() - 1; i >= 0; i--) {

                for(int num : bucket[i]) {

                    ans.push_back(num);

                    if(ans.size() == k)
                    return ans;

                }
            }
        return ans;
    }
};
