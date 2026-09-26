class Solution {
public:
    void subsequence(vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds, int ind)
    {
        ans.push_back(ds);

        for(int i = ind; i < nums.size(); i++)
        {
            if(i != ind && nums[i] == nums[i-1]) continue;

            ds.push_back(nums[i]);
            subsequence(nums, ans, ds, i + 1);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        subsequence(nums, ans, ds, 0);

        return ans;
    }
};
