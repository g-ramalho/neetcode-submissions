class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answ(nums.size());

        // from left to right, every number
        // is the multiplication of everyone before them
        answ[0] = 1;
        int acc = answ[0];
        for (int i=1;i<nums.size();i++) {
            answ[i] = nums[i-1] * acc;
            acc *= nums[i-1];
        }

        // then, from right to left,
        // multiply the current element
        // with everyone after them
        acc = nums[nums.size()-1];
        for (int j=nums.size()-2;j>=0;j--) {
            answ[j] = answ[j] * acc;
            acc *= nums[j];
        }

        return answ;
    }
};
