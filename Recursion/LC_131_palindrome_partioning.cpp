class Solution {
public:
    vector<vector<string>> ans;
    vector<string> ds;

    bool ispalindrome(string s, int start, int end)
    {
        while(start < end)
        {
            if(s[start] != s[end]) return false;

            start++;
            end--;
        }
        return true;
    }

    void solve(int ind, string s)
    {
        if(ind == s.size())
        {
            ans.push_back(ds);
            return;
        }

        for(int end = ind; end < s.size(); end++)
        {
            if(ispalindrome(s, ind, end))
            {
                ds.push_back(s.substr(ind, end - ind + 1));

                solve(end+1, s);

                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        solve(0, s);
        return ans;
    }
};
