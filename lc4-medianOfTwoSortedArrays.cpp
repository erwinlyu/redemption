#include <vector>
using namespace std;

//ref:
// https://medium.com/@hazemu/finding-the-median-of-2-sorted-arrays-in-logarithmic-time-1d3f2ecbeb46
// solution page of https://leetcode.com/problems/median-of-two-sorted-arrays/solution/
class Solution {
public:
    // time complexity: log(min(m,n))
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int aLen = nums1.size(), bLen = nums2.size();

        // make sure always search the array of shorter(or same) length.
        if (aLen > bLen) {
            swap(nums1, nums2);
            swap(aLen, bLen);
        }

        // since nums1 is guaranteed to be the shorter(or same length) array, 
        // it can contribute 0 to all of its elements.
        int aCountMin = 0, aCountMax = aLen;

        // number of elements on the left half side,
        // if total length is odd then left half has one more element than the right.
        int halfCount = (aLen + bLen + 1) / 2;

        double median = 0.0;
        while (aCountMin <= aCountMax) {

            // the snumber of elements on the left half of nums1 array.
            int aCount = aCountMin + (aCountMax - aCountMin) / 2;

            // the number of elements on the left half of nums2 array.
            int bCount = halfCount - aCount;

            //
            // before comparing nums1[aCount - 1] and nums2[bCount],
            // should make sure aCount is greater than 0 (otherwise Invalid Index Errors).
            // and this also implies that bCount is less than bLen,
            // for nums2 cannot contribute all its elements when nums1 contribute
            // at least 1 element.
            //
            if (aCount > 0 && nums1[aCount - 1] > nums2[bCount]) {
                // aCount is larger than the correct amount, decrease it.
                aCountMax = aCount - 1;
            }

            //
            // before comparing nums2[bCount - 1] and nums1[aCount],
            // should make sure aCount is less than aLen (otherwise Invalid Index Errors).
            // and this implies that bCount > 0, for nums2 has to contribute at least
            // one element if aCount < aLen.
            //
            else if (aCount < aLen && nums2[bCount - 1] > nums1[aCount]) {
                // aCount is smaller than the correcct amount, increase it.
                aCountMin = aCount + 1;
            }
            else {
                //
                // here, conditions:
                // 1) (#of left part == #of right part) || (#of left part == #of right part + 1)
                // and
                // 2) max element of left part <= min element of right part
                // are both satisfied.
                // however, corner cases still need to be carefully considered, which are:
                // aCount == 0 || aCount == aLen || bCount == 0 || bCount == bLen.s
                //

                // if aLen + bLen is odd, median is the greater value between
                // the end of the left part of nums1 and 
                // the end of the right part of nums2.
                int leftHalfEnd = 
                    aCount == 0 ?               // nums1 not contributing?
                        nums2[bCount - 1] :     // aCount == 0 implies bCount > 0
                        bCount == 0 ?           // nums2 is not contributing?
                            nums1[aCount - 1] : // bCount == 0 implies aCount > 0
                            max(nums1[aCount - 1], nums2[bCount - 1]);
                
                if ((aLen + bLen) % 2 == 1) {
                    median = leftHalfEnd / 1.0;
                    break;
                }

                // if aLen + bLen is even, need to find the min element of the right
                // part, which is the smaller one between nums1[aCount] and nums2[bCount].
                // but aCount can be equal to aLen and so is bCount.
                // thus, additional checks are needed.
                else {
                    int rightHalfEnd = 
                        aCount == aLen ?        // nums1 is all in the left part?
                            nums2[bCount] :     // aCount == aLen implies bCount < bLen
                            bCount == bLen ?    // nums2 is all in the left part?
                                nums1[aCount] : // bCount == bLen implies aCount < aLen
                                min(nums1[aCount], nums2[bCount]);
                    median = (leftHalfEnd + rightHalfEnd) / 2.0;
                    break;
                }
            }
        }
        return median;
    }
};