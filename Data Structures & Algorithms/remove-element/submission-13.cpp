class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int right=nums.size()-1;
        int left=right;
        while (left >= 0) {
            while (right >= 0 && nums[right] == val)
                --right;

            if (right < 0)
                return 0;

            left = right-1;
            while (left >= 0 && nums[left] != val)
                --left;

            if (left >= 0 && right >= 0)
                swap(nums[left], nums[right]);
        }

        return right - left;
    }
};