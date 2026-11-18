class Solution {
public:
    bool validPalindrome(string s) {
        int left=0, right=s.size()-1;

        while (left < right) {
            if (s[left] != s[right]) {
                bool all_equal = true;
                int buf_l = left, buf_r = right;
                left++;
                while (left < right) {
                    if (s[left] != s[right]) {
                        all_equal = false;
                        break;
                    }
                    left++; right--;
                }
                if (all_equal)
                    return true;

                all_equal = true;
                left = buf_l; right = buf_r-1;

                while (left < right) {
                    if (s[left] != s[right]) {
                        all_equal = false;
                        break;
                    }
                    left++; right--;
                }

                if (all_equal)
                    return true;
                
                return false;
            }

            left++; right--;
        }

        return true;
    }
};