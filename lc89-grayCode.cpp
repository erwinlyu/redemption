#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        // method 1: based on +/- operation between adjacent elements.
        // my own method, not straight forward, slow.
        // explanation：
        // for instance, n = 3, the operation sequence is:
        // 0, +1, +2, -1, +4, +1, -2, -1
        // initialized with the first element with 0, then perform those operations
        // sequentially, result can be generated.
        vector<int> res(1 << n, 0);
        int cnt = 1;
        for (int i = 0; i < n; ++i) {
            res[cnt++] = 1 << i;
            for (int j = 1; j < (1 << i); ++j) {
                res[cnt++] = ~res[cnt - 2 * j] + 1;
            }
        }
        for (int i = 1; i < (1 << n); ++i)  res[i] += res[i - 1];
        return res;

        // method 2: based on bit-operation
        // explanation can be found in: https://leetcode.com/problems/gray-code/discuss/29891/Share-my-solution
        // actually, this method can be regarded as the more thorough version of method 1.
        // they have similar time&space performance, too.
        vector<int> res(1, 0);
        for (int i = 0; i < n; ++i) {
            int k = res.size();
            for (int j = k - 1; j >= 0; --j) {
                // here, (res[j] + (1 << i)) can be substitute for OR operation,
                // but that would be slower and consumes a little more memory.
                res.push_back(res[j] | (1 << i));
            }
        }
        return res;

        // method 3: the most fancy and the fastest method..OTZ
        vector<int> res;
        for (int i = 0; i < pow(2, n); ++i) {   // here, pow(2,n) runs faster than (1<<n)
            res.push_back((i >> 1) ^ i);
        }
        return res;
    }
};