class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answ(nums.size());

        answ[0] = 1;
        // from left to right, every number
        // is the multiplication of everyone before them
        for (int i=1;i<nums.size();i++)
            answ[i] = nums[i-1] * answ[i-1];

        // then, from right to left,
        // multiply the current element
        // with everyone after them
        int acc = nums[nums.size()-1];
        for (int j=nums.size()-2;j>=0;j--) {
            answ[j] *= acc;
            acc *= nums[j];
        }

        return answ;
    }
};
