//freq array method
class Solution {
public:
    bool isAnagram(string s, string t) {

        int freq[26] = {0};

        for(char i : s) {
            freq[i - 'a']++;
        }

        for(char i : t) {
            freq[i - 'a']--;
        }

        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0) {
                return false;
            }
        }

        return true;
        
    }
};
