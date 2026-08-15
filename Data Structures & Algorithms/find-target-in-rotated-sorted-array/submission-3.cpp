class Solution {
public:
    int search(vector<int>& nums, int tar) {

    //in this que after finding mid, have to determine which half is sorted(left or right), then check whether our tar lies lies which that half and then move accordingly

        int st = 0;
        int end = nums.size() - 1;

        while( st <= end) {

            int mid = st + (end - st) / 2;

            if(nums[mid] == tar) {
                return mid;
            } 

            //check if left half is sorted
            if(nums[st] <= nums[mid]) {

                if(tar >= nums[st] && tar < nums[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            } else { // check if right half is sorted
                if(tar > nums[mid] && tar <= nums[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};
