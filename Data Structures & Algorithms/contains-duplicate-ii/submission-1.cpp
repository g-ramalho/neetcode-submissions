class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> idxs;
        for (int i=0;i<nums.size();i++) {
            if (idxs.find(nums[i]) != idxs.end() && i - idxs[nums[i]] <= k)
                return true;
            
            idxs[nums[i]] = i;
        }

        return false;
    }
};