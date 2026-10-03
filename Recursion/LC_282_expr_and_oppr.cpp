class Solution {
public:
    vector<string> ans;

    void solve(string& num, long long target, long long prev, long long value, string expr, int ind)
    {
        if(ind == num.size())
        {
            if(value == target) ans.push_back(expr);

            return;
        }

        for(int i = ind; i < num.size(); i++)
        {
            if(i > ind && num[ind] == '0') break;

            string cur = num.substr(ind, i - ind + 1);
            long long n = stoll(cur);

            if(ind == 0)
            {
                solve(num, target, n, n, cur, i+1);
            }
            else
            {
                solve(num, target, n, value + n, expr + '+' + cur, i+1);

                solve(num, target, prev * n, value - prev + prev * n, expr + '*' + cur, i+1);

                solve(num, target, -n, value - n, expr + '-' + cur, i+1);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        solve(num, target, 0, 0, "", 0);
        return ans;
    }
};
