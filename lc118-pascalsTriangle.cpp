#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        int rounds = 1;
        while (rounds <= numRows) {
            vector<int> layer;
            for (int i = 0; i < rounds; ++i) {
                if (i == 0 || i == rounds - 1)  layer.push_back(1);
                else    layer.push_back(res[rounds - 2][i - 1] + res[rounds - 2][i]);
            }
            res.push_back(layer);
            rounds++;
        }
        return res;
    }
};