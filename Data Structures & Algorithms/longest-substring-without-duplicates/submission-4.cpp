class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> st;

        int left = 0;
        int right = 0;

        int max_len = 0;

        while(right < s.length()) {

            if(st.find(s[right]) == st.end()) {

                st.insert(s[right]);
                right++;
                
                max_len = max(max_len, right - left);

            } else {

                st.erase(s[left]);
                left++;
            }
        }

        return max_len;
     }
};
