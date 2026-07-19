class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<long long, long long> m;
        for(int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }

        for(auto x : m)
        {
            if(x.second > n/2) return x.first;
        }
        return -1;
    }   
};
