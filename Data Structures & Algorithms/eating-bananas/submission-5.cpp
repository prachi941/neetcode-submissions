//koko cannot change a pile during any hour
//so we have to take ceiling value
//ultimately we have to find a min eating speed < h
// t.c. O(n log n); log n for bin search and n to iterate over the arr to check whether she can it in that speed
// here our arr range space is from 1 to max no of bananas in the arr and we do bin search on this arr

class Solution {
public:
    
    //helper function for finding total hours

    int cal_hours(vector<int>& piles, int k) {

        int totalHours = 0;

        for(int i = 0; i < piles.size(); i++) {
            int hour = ceil((double)piles[i]/ k);
            totalHours += hour;
        }

        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        //finding last ele of searchb space, i.e. max eating speed
        int max = piles[0];

        for(int i = 0; i < piles.size(); i++) {
            if(piles[i] > max) {
                max = piles[i];
            }
        }

        int st = 1;
        int end = max;

        int ans = end;

        while(st <= end) {

            int mid = st + (end - st) / 2;

            int hours = cal_hours(piles, mid);

            if(hours <= h) {

                ans = mid;

                end = mid - 1; // search for even lower speed
            } else {

                st = mid + 1;
            }
        }

        return ans;
    }

};
 