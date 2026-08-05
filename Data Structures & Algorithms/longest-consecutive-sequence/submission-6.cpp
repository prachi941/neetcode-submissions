class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st;

        for(int num : nums) {
            st.insert(num);
        }


        int longest = 0;

        for(int num : nums) {

          if(st.find(num - 1) == st.end()) { 

            int currNum = num;
            int currLen = 1;

            while(st.find(currNum + 1) != st.end()) {
                currNum++;
                currLen++;
            }

            longest = max(longest, currLen);
           }
        }

        return longest;
    }
};
