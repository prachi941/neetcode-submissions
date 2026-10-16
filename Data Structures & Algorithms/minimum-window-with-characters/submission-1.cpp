class Solution {
public: 
    string minWindow(string s, string t) {

        if(t.empty() || s.size() < t.size()) {
            return "";
        }

        int freq1[128] = {0};
        int freq2[128] = {0};

        for(int i = 0; i < t.size(); i++) {
            freq1[t[i]]++;
        }

        int left = 0;
        int matched = 0;
        int required = t.size();

        int minLen = INT_MAX;
        int startIdx = 0;
        
        for(int right = 0; right < s.size(); right++) {

            char ch = s[right];
            freq2[ch]++;

            if(freq1[ch] > 0 && freq2[ch] <= freq1[ch]) {
                matched++;
            }

            while(matched == required) {

                int currLen = right - left + 1;

                if(currLen < minLen) {
                    minLen = currLen;
                    startIdx = left;
                }

                char leftChar = s[left];

                freq2[leftChar]--;

                if(freq1[leftChar] > 0 && freq2[leftChar] < freq1[leftChar]) {
                    matched--;
                }

                left++;
            }

        }

        if(minLen == INT_MAX) {
            return "";
        }

        return s.substr(startIdx, minLen);
    }
};
