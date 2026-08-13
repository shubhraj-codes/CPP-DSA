class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();

        int i = 0;
        for(; i < n && s[i] == ' '; i++);

        int sign = 1;
        if(i < n && s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if(i < n && s[i] == '+') i++;

        long long ans = 0;

        for(; i < n; i++)
        {
            if(s[i] < '0' || s[i] > '9') break;

            ans = ans * 10 + (s[i]-'0');

            if (ans > INT_MAX)
                return sign == 1 ? INT_MAX : INT_MIN;
        }
        
        return ans * sign;

    }
};
