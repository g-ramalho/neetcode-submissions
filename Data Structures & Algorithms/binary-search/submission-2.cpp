class Solution {
public:
    int search(vector<int>& nums, int target) {
        int h = nums.size();
        int l = 0;
        int mid = (h - l) / 2 + l;

        while (true) {
            if (h < l || h < 0 || l == nums.size()) return -1;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                h = mid-1;
            else
                l = mid+1;

            mid = (h - l) / 2 + l;
        }
    }
};
