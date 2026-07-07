class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        vector<int> freq(128, 0);

        // count characters of t
        for (char c : t)
            freq[c]++;

        int left = 0, right = 0;
        int count = t.size();
        int minLen = INT_MAX, start = 0;

        while (right < s.size()) {
            // expand window
            if (freq[s[right]] > 0)
                count--;

            freq[s[right]]--;
            right++;

            // valid window
            while (count == 0) {
                // update answer
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                // shrink window
                freq[s[left]]++;
                if (freq[s[left]] > 0)
                    count++;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
