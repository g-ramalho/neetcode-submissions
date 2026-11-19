class Solution {
public:
    int get_insertion_idx(int key, int high, int low, vector<int>& nums1) {
        int h = high, l = low, mid = 0;
        while (l < h) {
            mid = (h - l) / 2 + l;
            if (nums1[mid] <= key)
                l = mid + 1;
            else
                h = mid;
        }

        return l;
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;

        if (nums2[n-1] <= nums1[0]) { // everyone in nums2 is smaller
            for (int i=m+n-1;i>=n;i--)
                nums1[i] = nums1[i-n];
            for (int i=0;i<n;i++)
                nums1[i] = nums2[i];

            return;
        }
        if (nums2[0] >= nums1[max(m-1, 0)]) { // everyone in nums2 is bigger
            for (int i=m;i<m+n;i++)
                nums1[i] = nums2[i-m];

            return;
        }

        for (int i=0;i<n;i++) {
            int k = get_insertion_idx(nums2[i], max(m+i, 0), 0, nums1);

            int j = m + i;
            while (j > k) {
                nums1[j] = nums1[j-1];
                j--;
            }

            // min(j, k) = insertion idx is before or after the earliest 0?
            nums1[min(j, k)] = nums2[i];
        }
    }
};