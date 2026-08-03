class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) { 

        int n = nums.size();

        int st = 0;
        int end = n - 1;

        while(st < end) {

            int sum = nums[st] + nums[end];

            if(sum == tar) {
                return {st + 1, end + 1};
            }

            else if(sum > tar) {
                end--;
            } 

            else {
                st++;
            }
        }

        return{};
    }
};
