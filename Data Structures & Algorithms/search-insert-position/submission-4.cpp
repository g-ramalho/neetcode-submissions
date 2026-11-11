class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int h = nums.size(), l = 0, mid = 0;
        while (l < h) {
            mid = (h - l) / 2 + l;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                h = mid;
            else
                l = mid+1;
        }

        return l;
    }
};