//first find mid normally
//then find the sorted half; either left of mid or right of mid will be sorted
//then check whether our tar lies in the range of sorted half or not; then accordingly change st/ end i.e mid+1/mid-1


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
