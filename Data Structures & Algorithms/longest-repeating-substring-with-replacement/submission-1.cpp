class Solution {
public:
    int characterReplacement(string s, int k) { 

        vector<int> freq(26, 0);

        int left = 0;
        int ans = 0;

        for(int right = 0; right < s.size(); right++) {
            
            freq[s[right] - 'A']++;

            int maxFreq = 0;

            for(int i = 0; i < 26; i++) {

                maxFreq = max(maxFreq, freq[i]);
            } 

            while((right - left + 1) - maxFreq > k) {

                freq[s[left] - 'A']--;
                left++;

                maxFreq = 0;

                for(int i = 0; i < 26; i++) {
                    maxFreq = max(maxFreq, freq[i]);
                }
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
        
    }
};
