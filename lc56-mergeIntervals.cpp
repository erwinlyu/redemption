#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.empty())   return res;
        sort(intervals.begin(), intervals.end());
        int lo = intervals[0][0], hi = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] <= hi)   hi = intervals[i][1] > hi ? intervals[i][1] : hi;
            else{
                res.push_back({lo, hi});
                lo = intervals[i][0];
                hi = intervals[i][1];
            }
        }
        res.push_back({lo, hi});
        return res;
    }
};
int main(){
    vector<vector<int>> input = {{1,4},{2,3}};
    Solution sln;
    vector<vector<int>> output = sln.merge(input);
    for(vector<int> item1 : output)
        cout << item1[0] << " " << item1[1] << endl;
    return 0;
}