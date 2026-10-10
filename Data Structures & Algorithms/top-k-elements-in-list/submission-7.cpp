class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        for(int n : nums) {
            freq[n]++;
        }

        priority_queue<pair<int, int>> maxHeap;

        for(auto& entry : freq) {
            maxHeap.push({entry.second, entry.first});
        }

        vector<int> ans;

        while(k--) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return ans;
    }
};
