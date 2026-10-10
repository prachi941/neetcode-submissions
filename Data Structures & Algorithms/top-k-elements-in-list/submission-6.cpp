//bucket sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        for(int n : nums) {
            freq[n]++;
        }

        int n = nums.size();
        vector<vector<int>> buckets(n + 1);

        for(auto& entry : freq) {
            buckets[entry.second].push_back(entry.first);
        }

        vector<int> ans;

        for(int f = n; f >= 1 && ans.size() < k; f--) {
            for(int x : buckets[f]) {
                ans.push_back(x);

                if(ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};
