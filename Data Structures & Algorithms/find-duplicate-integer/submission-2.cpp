//in question no mention of LL
//but we have to infer it
//have to imagine LL interleaving index and values
//slow = nums[slow]
//fast = nums[nums[fast]]
//do-while as both start from 0 so it won't enter while loop if we do while(slow != fast)
//Floyd's tortoise and hare algorithm

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = 0;
        int fast = 0;

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        slow = 0;
        
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
