class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        for(auto ch : s)
        {
            mp[ch]++;
        }

        vector<vector<char>> bucket(s.size() + 1);

        for(auto it : mp)
        {
            char ch = it.first;
            int freq = it.second;

            bucket[freq].push_back(ch);
        }

        string ans; 
        for(int i = s.size(); i >= 1; i--)
        {
            for(auto ch : bucket[i])
            {
                ans += string(i, ch);
            }
        }

        return ans;
    }
};
