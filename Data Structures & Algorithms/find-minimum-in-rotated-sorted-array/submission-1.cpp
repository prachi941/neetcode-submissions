class Solution {
public:
    int findMin(vector<int> &a) {
         
    int lo = 0; 
    int hi = a.size() - 1;

        int ans = INT_MAX;

        while(lo <= hi) {

                int mid = (lo + hi) / 2;

                if(a[lo] <= a[mid]) {

                    ans = min(ans, a[lo]);
                    lo = mid + 1;
                } 
                else {

                   hi = mid - 1;
                   ans = min(ans, a[mid]);
                }
            }

            return ans;
        }
    };
