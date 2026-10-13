class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        
        int left = 0;
        int right = nums.size() - 1;

        while(left < right) {

            if(nums[left] + nums[right] == tar) {
                return {1 + left, 1 + right};
            }

            else if(nums[left] + nums[right] < tar) {
                left++;
            }

            else{
                right--;
            }
        }

        return {};
    }
};
