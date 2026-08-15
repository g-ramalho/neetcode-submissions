class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> answ(nums.size() * 2);

        for (int i=0;i<nums.size();i++) {
            answ[i] = nums[i];
            answ[i+nums.size()] = nums[i];
        }

        return answ;
    }
};