class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> r = nums;
        r.insert(r.end(), r.begin(), r.end());
        return r;
    }
};