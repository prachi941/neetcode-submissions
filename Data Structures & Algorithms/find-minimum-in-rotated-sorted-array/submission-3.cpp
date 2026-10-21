class Solution {
public:
    int findMin(vector<int> &a) {

        int st = 0;
        int end = a.size() - 1;

        while(st < end) {

            int mid = st + (end - st)/2;

            if(a[mid] < a[end]) {
                end = mid;
            } else {
                st = mid + 1;
            }
        }

        return a[end];
        
    }
};
