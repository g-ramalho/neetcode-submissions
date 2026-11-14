class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0)
            return false;

        unordered_set<int> seen;
        int i = min(k, static_cast<int>(nums.size())-1);
        for (int j=i-1;j>=0;j--) {
            if (seen.contains(nums[j]))
                return true;
            seen.insert(nums[j]);
        }

        for (;i<nums.size();i++) {
            if (seen.contains(nums[i]))
                return true;

            seen.erase(nums[i-k]);
            seen.insert(nums[i]);
        }

        return false;
    }
};