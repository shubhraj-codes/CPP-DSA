class Solution {
public:
    int RecursiveBinarySearch(vector<int>& nums, int low, int high, int target)
    {
        if (low > high)
        {
            return -1;
        }
        
        int mid = (low+high)/2;

        if(nums[mid] == target) return mid;
        else if(target < nums[mid]) return RecursiveBinarySearch(nums, low, mid-1, target);
        return RecursiveBinarySearch(nums, mid+1, high, target);
    }   
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return RecursiveBinarySearch(nums, 0, n-1, target);
    }
};
