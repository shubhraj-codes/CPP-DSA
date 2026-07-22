class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int low = 1, high = INT_MIN;
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] > high) high = nums[i];
        }

        while(low <= high)
        {
            int mid = (low + high)/2;

            long long sum = 0;

            for(int i = 0; i < n; i++)
            {
                sum += ceil(((double)nums[i]/mid));
            }

            if(sum <= threshold) ans = mid, high = mid-1;

            else low = mid+1;
        }
        return ans;
    }
};
