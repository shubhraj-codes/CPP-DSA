class Solution {
public:
    vector<int> genrows(int row)
    {
        long long ans = 1;

        vector<int> ansrow;
        ansrow.push_back(1);

        for(int column = 1; column < row; column++)
        {
            ans *= row-column;
            ans /= column;
            ansrow.push_back(ans);
        }
        return ansrow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i = 1; i <= numRows; i++)
        {
            ans.push_back(genrows(i));
        }
        return ans;
    }
};
