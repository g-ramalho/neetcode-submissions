class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> answ;

        for (int i=0;i<nums.size();i++)
            answ.push_back(nums[i]);

        for (int i=0;i<nums.size();i++)
            answ.push_back(nums[i]);

        return answ;
    }
};