//Find a window in s2 whose character-frequency array matches s1
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.length() > s2.length()) {
            return false;
        }

        int freq1[26] = {0};
        int freq2[26] = {0};

        for(int i = 0; i < s1.length(); i++) {
            freq1[s1[i] - 'a']++;
        }

        int left = 0;
        int right = 0;

        while(right < s2.length()) {

            freq2[s2[right] - 'a']++;
            right++;

            if((right - left) > s1.length()) {
                freq2[s2[left] - 'a']--;
                left++;
            }

            if(right - left == s1.length()) {
                
                bool same = true;

                for(int i = 0; i < 26; i++) {
                    if(freq1[i] != freq2[i]) {
                        same = false;
                        break;
                    }
                }

                if(same) {
                    return true;
                }

            }

        }

    return false;

    }
        
};
