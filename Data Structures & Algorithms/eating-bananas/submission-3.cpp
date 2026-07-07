class Solution {
public:

    int calculateHours(vector<int>& piles, int k){

        int totalHours = 0;

        for(int i = 0; i < piles.size(); i++){
            totalHours += ceil((double)piles[i]/k);

        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h){

        int maxi = piles[0];

        for(int i = 0; i < piles.size(); i++){
            if(piles[i] > maxi){
                maxi = piles[i];
            }
        }

        int lo = 1;
        int hi = maxi;

        while(lo <= hi){

            int mid = (lo + hi)/ 2;

            int hours = calculateHours(piles, mid);

            if(hours <= h){

                hi = mid - 1;
            } else {
                
                lo = mid + 1;
            }
        }

        return lo;
    }
};
