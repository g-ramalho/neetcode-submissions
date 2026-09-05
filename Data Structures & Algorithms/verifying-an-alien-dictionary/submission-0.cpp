class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int alien[26] = {0};
        for (int i=0;i<order.size();i++)
            alien[order[i] - 'a'] = i;

        for (int i=0;i<words.size()-1;i++) {
            const string &w = words[i];
            const string &o = words[i+1];
            for (int j=0;j<w.size();j++) {
                if (j == o.size()) // equal strings, but the smaller one is placed later
                    return false;
                if (w[j] != o[j]) {
                    if (alien[w[j] - 'a'] > alien[o[j] - 'a'])
                        return false;
                    break;
                }
            }
        }

        return true;
    }
};