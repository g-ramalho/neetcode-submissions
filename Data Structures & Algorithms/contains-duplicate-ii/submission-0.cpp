class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0, j=i+1;
        while (j < nums.size()) {
            for (int n=j;n<=i+k;n++){
                if (n == nums.size())
                    break;
                if (nums[i] == nums[n])
                    return true;
            }
            i++; j++;
        }

        return false;
    }
};