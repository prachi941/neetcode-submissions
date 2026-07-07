class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, 0);  // ASCII characters
        
        int left = 0, right = 0;
        int maxLen = 0;

        while (right < s.length()) {
            // If duplicate found, shrink window
            while (freq[s[right]] == 1) {
                freq[s[left]]--;
                left++;
            }

            // Add current character
            freq[s[right]]++;

            // Update max length
            maxLen = max(maxLen, right - left + 1);

            right++;
        }

        return maxLen;
    }
};