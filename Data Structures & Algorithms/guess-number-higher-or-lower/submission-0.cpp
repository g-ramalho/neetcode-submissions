/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int h = n, l = 1, mid=1;
        while (l<=h) {
            mid = (h - l) / 2 + l;
            int g = guess(mid);
            if (g == 0)
                return mid;
            else if (g < 0)
                h = mid-1;
            else
                l = mid+1;
        }

        return mid;
    }
};