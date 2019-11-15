#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty()){
            return (nums2[(nums2.size() - 1) / 2] + nums2[nums2.size() / 2]) / 2.0;
        }
        if(nums2.empty()){
            return (nums1[(nums1.size() - 1) / 2] + nums1[nums1.size() / 2]) / 2.0;
        }
        int n = nums1.size(), m = nums2.size();
        if(n == 1 && m == 1)
            return (nums1[0] + nums2[0]) / 2.0;
        int p = 0, q = 0;
        while((p + q) < (n + m) / 2){
            cout << "this round, the p and q is: " << p << " " << q << endl;
            if(nums1[p] < nums2[q]){
                p = binarySearch(nums1, p, nums2[q]);
            }
            else if(nums1[p] > nums2[q]){
                q = binarySearch(nums2, q, nums1[p]);
            }
            else{
                if(p < n)   p++;
                else    q++;
            }
            if(p == n || q == m)    break;
        }
        cout << "the final p and q is: " << p << " " << q << endl;
        if(p == n){
            if(m == n)  return (nums1[n - 1] + nums2[q]) / 2.0;
            else if(m > n){
                if((n + m) % 2 == 1)    return 1.0 * nums2[(m - n) / 2];
                else    return (nums2[(m - n) / 2 - 1] + nums2[(m - n) / 2]) / 2.0;
            }
            else{
                if((n + m) % 2 == 1)    return 1.0 * nums1[(n + m + 1) / 2 - q - 1];
                else    return (nums1[(n + m) / 2 - q - 1] + nums1[(n + m) / 2 - q]) / 2.0;
            }
        }
        else if(q == m){
            if(m == n)  return (nums1[p] + nums2[m - 1]) / 2.0;
            else if(n > m){
                if((n + m) % 2 == 1)    return 1.0 * nums1[(n - m) / 2];
                else    return (nums1[(n - m) / 2 - 1] + nums1[(n - m) / 2]) / 2.0;
            }
            else{
                if((n + m) % 2 == 1)    return 1.0 * nums2[(n + m + 1) / 2 - p - 1];
                else    return (nums2[(n + m) / 2 - p - 1] + nums2[(n + m) / 2 - p]) / 2.0;
            }
        }
        else{
            if((n + m) % 2 == 1)   return min(nums1[p], nums2[q]) * 1.0;
            else    return (nums1[p] + nums2[q]) / 2.0;
        }
    }

    int binarySearch(vector<int>& num, int left, int target){
        int right = num.size() - 1;
        if(num[right] < target) return right + 1;
        while(left < right){
            int mid = (left + right) / 2;
            if(num[mid] == target)  return mid;
            else if(num[mid] < target)   left = mid + 1;
            else    right = mid;
        }
        return left;
    }
};

int main(){
    vector<int> input1 = {1,2};
    vector<int> input2 = {-1,3};
    Solution sln;
    cout << "The median is " << sln.findMedianSortedArrays(input1, input2);
    return 0;
}