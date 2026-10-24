class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int hash[256];

        for(int i = 0; i < 256; i++) {
            hash[i] = -1;
        }
        
        int l = 0, r = 0;
        int max_len = 0;

        while(r < s.size()) {
            if(hash[s[r]] != -1 && hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }

            int len = r - l + 1;
            max_len = max(max_len, len);

            hash[s[r]] = r;//update the most recent occurence of s[r]
            r++;
        }

        return max_len;
    }
};