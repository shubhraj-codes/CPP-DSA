class Solution {
public:
    vector<vector<int>> ans;
    vector<int> ds;

    void sum(int start, int k, int n)
    {
        if(ds.size() == k) 
        {
            if(n == 0)
            {
                ans.push_back(ds);
            }
            return;
        }

        for(int i = start; i <= 9; i++)
        {
            if(i > n) break;

            ds.push_back(i);
            sum(i+1, k, n-i);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {

        sum(1, k, n);

        return ans;
    }
};
