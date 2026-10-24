//unordered_map
//directly jumps to index after the duplicate
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> mp;

        int left = 0;
        int maxLen = 0;

        for(int right = 0; right < s.size(); right++) {

            char ch = s[right];

            if(mp.find(ch) != mp.end() && mp[ch] >= left) { //means ch alredy there in curr window
                left = mp[ch] + 1;//move left ptr past that ch (so where it was seen + 1)
            }

            mp[ch] = right;//add that duplicate's ch index in hash map now (like the index it was seen recently)

            int currLen = right - left + 1;
            maxLen = max(maxLen, currLen);
        }

        return maxLen;
        
    }
};
