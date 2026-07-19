class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> m;
        
        for(int i = 0; i< n; i++)
        {
            int finding = target - nums[i];
            if(m.find(finding) != m.end())
            {
                return  {i, m[finding]};
            }
            m[nums[i]] = i;
        }
        return {-1,-1};
    }
};
