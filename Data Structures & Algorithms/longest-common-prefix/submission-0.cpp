class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pfx = "";

        int i=0;
        while (1) {
            char curr=0;
            for (const string &s : strs) {
                if (!curr)
                    curr = s[i];
                
                if (i >= s.size() || curr != s[i])
                    return pfx;
            }
            if (curr)
                pfx += curr;
            i++;
        }

        return pfx;
    }
};