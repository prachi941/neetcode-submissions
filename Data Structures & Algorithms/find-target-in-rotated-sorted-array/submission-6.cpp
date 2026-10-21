class Solution {
public:
    int search(vector<int>& a, int tar) {

        int st = 0;
        int end = a.size() - 1;

        while(st <= end) {

            int mid = st + (end - st)/2;

            if(a[mid] == tar) {
                return mid;

            } else if(a[st] <= a[mid]){ //array left sorted

                if(tar >= a[st] && tar <= a[mid]) {
                end = mid - 1;
                } else {
                    st = mid + 1;
                }

            } else {//array right sorted

                if(tar >= a[mid] && tar <= a[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            
        }

        return -1;
        
    }
};
