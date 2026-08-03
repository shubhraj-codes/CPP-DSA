class Solution {
public:
    bool isIsomorphic(string s, string t) {
    int n = s.size();
  
    unordered_map<char, char> mpST;
    unordered_map<char, char> mpTS;

    for (int i = 0; i < n; i++)
    {
        char c1 = s[i], c2 = t[i];
        if(mpST.count(c1) && mpST[c1] != c2 || mpTS.count(c2) && mpTS[c2] != c1)
        {
            return false;
        }
        
        mpST[c1] = c2;
        mpTS[c2] = c1;
    }
    
    return true;
    }
};
