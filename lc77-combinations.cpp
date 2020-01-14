#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        recursive_method(comb, 1, 0, n, k);
        return combs;
    }
private:
    vector<vector<int>> combs;
    vector<int> comb;

    // 80ms 12,8MB
    void recursive_method(vector<int>& comb, int idx, int cnt, int n, int k) {
        if (cnt >= k) {
            combs.push_back(comb);
            return;
        }
        for (int i = idx; i <= n; ++i) {
            comb.push_back(i);
            recursive_method(comb, i + 1, cnt + 1, n, k);
            comb.pop_back();
        }
    }

    // 56ms 11.6MB
    // reference:https://leetcode.com/problems/combinations/discuss/26992/Short-Iterative-C%2B%2B-Answer-8ms
    vector<vector<int>> iterative_method(int n, int k) {
        /* explanation: say, n = 5, k = 3
            [0,0,0] -> [1,0,0] -> [1,1,0] -> [1,2,0] -> [1,2,2] -> [1,2,3] ->
            [1,2,4] -> [1,2,5] -> [1,2,6] -> [1,3,6] -> [1,3,4] -> [1,3,5] -> ... */
        vector<vector<int>> res;
        vector<int> pmt(k, 0);
        int i = 0;
        while (i >= 0) {
            pmt[i]++;   // increments first.

            // if pmt[i] is too large that the numbers left between it and n are not
            // enough to fill the blanks after it, index decrements.
            if (pmt[i] > n - (k - i - 1))    --i;   // optimized over (pmt[i] > n).
            
            //if index meets the last element, push it into the res.
            else if (i == k - 1)    res.push_back(pmt);

            // index increments, and the gives the new elements the same value as its predecessor,
            // it will increment in the next loop after all.
            else {
                ++i;
                pmt[i] = pmt[i - 1];
            }
        }
        return res;
    }
};