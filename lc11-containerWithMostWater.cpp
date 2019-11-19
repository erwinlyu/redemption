#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
    int height;
    int pos;
    Node(int x, int y) : height(x), pos(y) {}
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        // brute force
/*         int maxWater = 0;
        for(int i = 0; i < height.size() - 1; i++){
            for(int j = i; j < height.size(); j++){
                int tempWater = min(height[i], height[j]) * (j - i);
                if(tempWater > maxWater)    maxWater = tempWater;
            }
        }
        return maxWater; */

        // double pointer
        // very clever and intuitive thoughts
        // proof:
        // "We starts with the widest container, 
        // l = 0 and r = n - 1. Let's say the left one is shorter: h[l] < h[r]. 
        // Then, this is already the largest container the left one can possibly form. 
        // There's no need to consider it again. Therefore, 
        // we just throw it away and start again with l = 1 and r = n -1."
        int p = 0, q = height.size() - 1;
        int maxWater = 0;
        while(p < q){
            maxWater = max(maxWater, min(height[p], height[q]) * (q - p));
            if(height[p] < height[q])   p++;
            else    q++;
        }
        return maxWater;
    }
};

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution sln;
    cout << sln.maxArea(height);
    return 0;
}