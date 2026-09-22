class Solution {
public:
    void findCombination(int ind, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int> ds)
    {
        if(ind == candidates.size())
        {
            if(target == 0) 
            {
                ans.push_back(ds);
            }
            return;
        }

        if(candidates[ind] <= target)
        {
            ds.push_back(candidates[ind]);
            findCombination(ind, candidates, target-candidates[ind], ans, ds);
            ds.erase(ds.end()-1);
        }
        findCombination(ind+1, candidates, target, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, candidates, target, ans, ds);
        return ans;
    }
};
