// Problem: Remove duplicates form a sorted array
// Platform: LeetCode
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] != nums[j])
            {
                nums[j+1] = nums[i];
                j++;
            }
        }
        return j+1;
    }
};
