class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        int prefsum = 0;

        unordered_map<long long,long long> m;
        m[0] = 1;

        for(int i = 0; i < n; i++)
        {
            prefsum += nums[i];

            int remove = prefsum - k;
            cnt += m[remove];
            m[prefsum]++;
        }
        return cnt;
    }
};
