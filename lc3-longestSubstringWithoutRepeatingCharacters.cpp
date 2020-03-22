#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 快手2020秋招算法岗笔试题
class Solution {
public:
    // method 1:这个不算dp,应该叫双指针法
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0; //in case the input string is empty
        int maxlen = 0;
        vector<int> dp;
        dp.resize(s.length());
        dp[0] = 1;
        for(int i = 1; i < s.length(); i++){
            dp[i] = dp[i - 1] + 1;
            for(int j = i - dp[i - 1]; j < i; j++){
                if(s[j] == s[i]) dp[i] = i - j;
            }
        }
        for(int i = 0; i < dp.size(); i++){
            if(dp[i] > maxlen)  maxlen = dp[i];
        }
        return maxlen;
    }

    // method 2: 优化的滑动窗口法
    // start和end围成的窗口s[start, end)在字符串s上滑动, 窗口长度就是end - start
    // 数组bucket维护当前窗口中的每个字符的最新index
    int optimized_sliding_window(string s) {
        int start(0), end(0), length(0), res(0), s_len = s.size();

        // 未拓展的ASCII码的数量是128个. 拓展的话就是256个.
        vector<int> bucket(128, -1);

        while (end < s_len) {
            int temp = s[end] - ' '; // 先不把s[end]加入窗口,而是先观察它是否与窗口中的字符重复
            
            // 当且仅当s[end]的字符与窗口内的字符重复时
            if (bucket[temp] >= start) {    // 条件成立意味着有一个跟s[end]相同的字符的index大于start,即该字符出现在了窗口中
                start = bucket[temp] + 1;   // 窗口的start移动到这个重复了的字符的下一个位置
                length = end - start;   // 新的窗口长度就是end减去新的start
            }

            // 更新s[end]的新索引
            bucket[temp] = end;

            end++;
            length++;
            res = max(res, length);
        }
    }
};