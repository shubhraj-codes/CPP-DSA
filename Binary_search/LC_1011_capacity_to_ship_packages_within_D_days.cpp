class Solution {
public:
    int findDays(vector<int>& weights, int capacity)
    {
        int day = 1, load = 0;
        int n = weights.size();
        for(int i = 0; i < n; i++)
        {
            if(weights[i]+load > capacity)
            {
                day += 1;
                load = weights[i];
            }
            else load += weights[i];
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = 0, high = 0;
        for(int i = 0; i < n; i++)
        {
            high += weights[i];
            low = max(low, weights[i]);
        }

        while(low <= high)
        {
            int mid = (low + high)/2;

            int day = findDays(weights, mid);

            if(day <= days) high = mid-1;

            else low = mid+1;
        }
        return low;
    }
};
