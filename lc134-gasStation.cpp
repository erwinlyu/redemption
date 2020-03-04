#include <vector>
using namespace std;
class Solution {
public:
    // method 1: my own brute force method.
    int canCompleteCircuit_bf(vector<int>& gas, vector<int>& cost) {
        if (gas.empty())  return -1;
        int res = -1;
        for (int i = 0; i < gas.size(); ++i) {
            if (gas[i] < cost[i])   continue;
            if (can_travel_around(i, gas, cost)) {
                res = i;
                break;
            }
        }
        return res;
    }

    // method 2: modified brute force with two facts. Much faster(130+ms vs. 4ms. for 31 cases.)
    // ref: https://leetcode.com/problems/gas-station/discuss/42568/Share-some-of-my-ideas.
    // fact 1: if total total gas is no less than total cost, than there must be a solution.
    // fact 2: if starts from A and cannot reach B, then any station between A and B cannot
    //          reach B. (B is the first unreachable station for A)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0;

        // check fact 1.
        for (int i = 0; i < gas.size(); ++i) {
            tank += gas[i] - cost[i];
        }
        if (tank < 0)   return -1;

        // use fact 2 to find the start station.
        tank = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            tank += gas[i] - cost[i];
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        return start;
    }

private:
    bool can_travel_around(int station, vector<int>& gas, vector<int>& cost) {
        int stations = gas.size(), rest_gas = 0;
        for (int i = 0; i < stations; ++i) {
            int j = (i + station) % stations;
            rest_gas += gas[j] - cost[j];
            if (rest_gas < 0)   return false;
        }
        return true;
    }
};