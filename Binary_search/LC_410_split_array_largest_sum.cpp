class Solution {
public:
    bool isPossible(vector<int> &nums, int barrier,int m)
    {
        int n = nums.size();
        int allocatedStu = 1, pages = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] > barrier) return false;

            if(pages + nums[i] > barrier)
            {
                allocatedStu += 1;
                pages = nums[i];
            }
            else pages += nums[i];
        }
        if(allocatedStu > m) return false;

        return true;
    }
    int findPages(vector<int> &nums, int m)  {
        int n = nums.size();

        int low = 0, high = 0;

        for(int i = 0; i < n; i++)
        {
            low = max(low, nums[i]);
            high += nums[i];
        }

        while(low <= high)
        {
            int mid = (low + high)/2;

            if(isPossible(nums, mid, m)) high = mid-1;

            else low = mid+1;
        }
        return low;
    }

    int splitArray(vector<int>& nums, int k) {
        return findPages(nums, k);
    }
};
