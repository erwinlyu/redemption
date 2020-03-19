#include <vector>
using namespace std;
class Solution {
public:
    // method 1: 线性搜索
    int minArray(vector<int>& numbers) {
        int res = numbers[0];
        for (int i = 1; i < numbers.size(); ++i) {
            if (numbers[i] < numbers[i - 1]) {
                res = numbers[i];
                break;
            }
        }
        return res;
    }

    // method 2: 二分法
    // 核心思想: 旋转后的数组分为左半部分和右半部分两部分,其中右半部分的左端点也就是旋转点;最极端的
    //          情况就是左半部分为空,即全部元素都旋转到右半部分.使用二分法搜索旋转点(的value).
    int method_2(vector<int>& numbers) {
        int lo = 0, hi = numbers.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (numbers[mid] < numbers[hi]) {   // mid在右半部分,旋转点在[lo, mid]中
                hi = mid;
            }
            else if (numbers[mid] > numbers[hi]) {  // mid在左半部分,旋转点在[mid+1, hi]中
                lo = mid + 1;
            }
            else {  // the tricky part. 不确定mid在左还是在右,用hi--来缩小搜索范围
                    // 这种做法可能导致找不到旋转点的index,但仍能找到旋转点的value.
                hi--;
            }
        }
        return numbers[lo];
    }
};