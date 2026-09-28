class Solution {
public:
    vector<string> ans;
    vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void solve(int i, string digits, string ds)
    {
        if(i == digits.size())
        {
            ans.push_back(ds);
            return;
        }

        string letters = mp[digits[i] - '0'];

        for(auto ch : letters)
        {
            ds.push_back(ch);
            solve(i+1, digits, ds);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        solve(0, digits, "");
        return ans;
    }
};
