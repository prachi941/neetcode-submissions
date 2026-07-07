class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        
        int ans = high;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            long long hours = 0;
            
            // calculate total hours needed at speed mid
            for(int pile : piles) {
                hours += (pile + mid - 1) / mid; // ceil division
            }
            
            if(hours <= h) {
                ans = mid;        // possible answer
                high = mid - 1;  // try smaller k
            } else {
                low = mid + 1;   // need bigger k
            }
        }
        
        return ans;
    }
};