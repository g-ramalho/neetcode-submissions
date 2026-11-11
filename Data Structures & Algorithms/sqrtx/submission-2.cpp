class Solution {
public:
    int mySqrt(int x) {
        long long h = x, l = 0, mid = 0;
        while (l <= h) {
            mid = (h - l) / 2 + l;
            if (mid * mid == x)
                return mid;
            else if (mid * mid > x)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return static_cast<int>(h);
    }
};