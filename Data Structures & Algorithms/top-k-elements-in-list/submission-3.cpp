class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        for(int num : nums) {
            mp[num]++;
        }

        //t.c. O(n log n)
        priority_queue<pair<int, int>> pq;

        for(auto &it : mp) {

            pq.push({it.second, it.first}); // freq, number.Because priority queues compare the first value by default.
        }

        vector<int> ans;

        while(k--) {

            ans.push_back(pq.top().second);

            pq.pop();
        }

        return ans;
    }
};
