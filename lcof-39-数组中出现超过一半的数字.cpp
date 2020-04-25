#include <iostream>
#include <vector>
using namespace std;
/**
 * 摩尔投票
 * cand为候选人，cnt为票数
 * 如果票数为0则置当前元素为候选人
 * 如果候选人等于当前元素则票数增加1(刚刚“当选”候选人的元素当然会投票给自己)
 * 如果候选人不等于当前元素则票数减去1
 * 最后的候选人就是得票超过一半的众数
 * 
 * 其他解法还包括：哈希表法和排序法
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = -1, cnt = 0;
        for (auto num : nums) {
            if (!cnt)   cand = num;
            if (cand == num)  cnt++;
            else    cnt--;
        }
        return cand;
    }
};