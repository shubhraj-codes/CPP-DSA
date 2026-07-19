
// Problem: Check if Array Is Sorted and Rotated
// Platform: LeetCode
// Time Complexity: O(n)
// Space Complexity: O(1)class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > nums[(i+1) % n]) cnt++;
        }
        if(cnt <= 1) return true;
        else return false;
    }
};
