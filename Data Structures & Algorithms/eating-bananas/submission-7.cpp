class Solution {
public:
        int findMax(vector<int> &v) {//for finding the maximum possible speed for our range for BS
            int max = v[0];
            for(int i = 0; i < v.size(); i++) {
                if(v[i] > max) {
                    max = v[i];
                }
            }
            return max;
        }

        int calculateTotalHours(vector<int> &v, int k) {
            int totalH = 0;
            for(int i = 0; i < v.size(); i++) {
                totalH += ceil((double) v[i]/ (double)k);
            }

            return totalH;
        } 

        int minEatingSpeed(vector<int>& v, int h) {

            int st = 1;
            int end = findMax(v);

            while(st <= end) {
                int mid = st + (end - st)/2;
                int totalH = calculateTotalHours(v, mid);

                if(totalH <= h) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            }

        return st;
    }
};
