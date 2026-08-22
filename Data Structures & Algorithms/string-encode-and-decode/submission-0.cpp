class Solution {
public:

    string encode(vector<string>& strs) {
        string r = to_string(strs.size()) + '#';
        for (const string& s : strs) 
            r += s + '\0';
        
        return r;
    }

    vector<string> decode(string s) {
        string len;
        int i = 0;
        while (s[i] != '#') {
            len += s[i];
            i++;
        }
        i++;
        vector<string> r(stoi(len));
        int str_idx = 0;
        while (i < s.size()) {
            if (s[i] != '\0')
                r[str_idx] += s[i];
            else
                str_idx++;

            i++;
        }

        return r;
    }
};
