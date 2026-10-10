class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(st.find(nums[i] - 1) == st.end()) { // we didn't found predecessor
                int curr = nums[i]; // so make the curr ele as starting point
                int len = 1;

                while(st.find(curr + 1) != st.end()) {

                    curr++;
                    len++;
                }

                longest = max(longest, len);
            }
        }

        return longest;
    }
};
