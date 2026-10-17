class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        //for 1st wind
        for(int i = 0; i < k; i++) {
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        //for consecutive windows
        for(int i = k; i < nums.size(); i++) {
            ans.push_back(nums[dq.front()]);//store ans for previous wind

            //for maintaining viable window
            //remove elements not part of curr window
            while(dq.size() > 0 && dq.front() <= i - k) {
                dq.pop_front();
            }

            //remove the values less than curr ele
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);

        return ans;
        
    }
};
