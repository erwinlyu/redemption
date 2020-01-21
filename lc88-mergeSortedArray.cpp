#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cnt = m-- + n-- - 1;
        while (cnt >= 0) {
            if (m < 0)                      nums1[cnt--] = nums2[n--];
            else if (n < 0)                 nums1[cnt--] = nums1[m--];
            else if (nums2[n] > nums1[m])   nums1[cnt--] = nums2[n--];
            else                            nums1[cnt--] = nums1[m--];
        }
    }
};