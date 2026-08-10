//replacements needed = window len - freq of most frequent char
//replacements needed <= k
class Solution {
public:
    int characterReplacement(string s, int k) {

    
    int freq[26] = {0};
    
    int left = 0;
    int right = 0;

    int max_freq = 0;
    int max_len = 0;

    while(right < s.length()) {

        freq[s[right] - 'A']++;
        max_freq = max(max_freq, freq[s[right] - 'A']);
        right++;

        while((right - left) - max_freq > k) {
            freq[s[left] - 'A']--;
            left++;
        }

        max_len = max(max_len, right - left);
    }
    
    return max_len;

    }
};
