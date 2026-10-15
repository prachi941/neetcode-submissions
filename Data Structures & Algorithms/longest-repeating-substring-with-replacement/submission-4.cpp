class Solution {
public:
    int characterReplacement(string s, int k) {

        int freq[26] = {0};

        int left = 0;
        int right = 0;

        int maxFreq = 0;
        int maxLen = 0;

        for(int right = 0; right < s.size(); right++) {
            
            freq[s[right] - 'A']++;

            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            int currLen = right - left + 1;

            int replacementsNeeded = currLen - maxFreq;

            while(replacementsNeeded > k) {

                freq[s[left] - 'A']--;
                left++;

                currLen = right - left + 1;
                replacementsNeeded = currLen - maxFreq;

            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
        
    }
};
