#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
// reference:
// https://leetcode.com/problems/group-anagrams/discuss/19200/C%2B%2B-unordered_map-and-counting-sort
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        if(strs.empty())    return res;
        for(string str : strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            map[temp].push_back(str);
        }
        for(auto item : map){
            res.push_back(move(item.second));
        }
        return res;
    }
};