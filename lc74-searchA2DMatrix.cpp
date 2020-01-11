#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search, but treat this "sorted matrix" as a sorted array.
        int row = matrix.size();
        if (row == 0)   return false;
        int col = matrix[0].size();
        if (col == 0)   return false;
        int lo = 0, hi = row * col - 1;
/*         while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int mid_val = matrix[mid / col][mid % col];
            if (mid_val == target)  return true;
            else if (mid_val < target)  lo = mid + 1;
            else    hi = mid - 1;
        }
        return false; */

        // another interesting binary search
        while (lo != hi) {
            int mid = (lo + hi - 1) >> 1;
            int mid_val = matrix[mid / col][mid % col];
            if (mid_val < target)   lo = mid + 1;
            else    hi = mid;
        }
        return matrix[hi / col][hi % col] == target;
    }
};
int main() {
    //vector<vector<int>> input = {{2,3,5,7},{10,11,16,20},{23,30,34,50}};
    vector<vector<int>> input = {{1,1}};
    Solution sln;
    int target;
    scanf("%d", &target);
    if (sln.searchMatrix(input, target)) printf("true\n");
    else    printf("false\n");
    return 0;
}