#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    // method 1, use unordered_set
    // ref:https://leetcode.com/problems/longest-consecutive-sequence/discuss/41057/Simple-O(n)-with-Explanation-Just-walk-each-streak
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())   return 0;
        int longest = 0;

        // store all the numbers in hash table in the first place;
        unordered_set<int> numset(nums.begin(), nums.end());

        // traverse all the element in the hash table.
        for (auto it = numset.begin(); it != numset.end(); ++it) {
            int temp = *it;

            // if a num is the start of a streak.
            if (numset.find(temp - 1) == numset.end()) {
                temp++;

                // stop when the incremented number is not in the hash table.
                while (numset.find(temp) != numset.end()) {
                    temp++;
                }

                // get the length of this streak and update the max length.
                longest = max(longest, temp - *it);
            }
        }
        return longest;
    }

    // method 2, use unordered_map
    int method_2(vector<int>& nums) {
        unordered_map<int, int> lenMap;
        int res = 0;
        for (int num : nums) {
            // if num is already exists, ignore.
            if (lenMap.find(num) != lenMap.end())   continue;

            // get the length of num's left sequence if it exists, otherwise gets 0.
            // do the same to the right.
            int leftLen = lenMap.find(num - 1) == lenMap.end() ? 0 : lenMap[num - 1];
            int rightLen = lenMap.find(num + 1) == lenMap.end() ? 0 : lenMap[num + 1];

            // sum: the length of sequence that num lies in.
            int sum = leftLen + rightLen + 1;
            lenMap[num] = sum;

            // keep track of the max length.
            res = max(res, sum);

            // extend the length to the boundry of this sequence.
            // will do nothing if num has no neighbours.
            lenMap[num - leftLen] = sum;
            lenMap[num + rightLen] = sum;
        }
        return res;
    }
};