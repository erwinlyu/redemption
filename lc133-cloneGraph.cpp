#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Defination for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// ref:https://leetcode.com/problems/clone-graph/discuss/42313/C%2B%2B-BFSDFS

class Solution {
public:
    // method 1: bfs
    Node* cloneGraph_BFS(Node* node) {
        if (!node)  return node;
        Node* copy_of_node = new Node(node->val);
        copies[node] = copy_of_node;    // 用unordered_map维护的原graph的复制Node的集合
        queue<Node*> todo;
        todo.push(node);
        while (!todo.empty()) {
            Node* cur = todo.front();   // 从队首取出一个节点
            todo.pop();
            for (Node* neighbor : cur->neighbors) {
                if (copies.find(neighbor) == copies.end()) {    // 仅当考察的neighbor节点未复制过时
                    todo.push(neighbor);    // 配合if的条件,确保原graph中的每个Node在todo中出现且仅出现一次
                    copies[neighbor] = new Node(neighbor->val); // 将未出现过的这个neighbor节点添加进copies
                }
                copies[cur]->neighbors.push_back(copies[neighbor]); // 注意,push进去的不应该是neighbor,而是其复制Node,即copies[neighbor]
            }
        }
        return copy_of_node;
    }

    // method 2: dfs
    Node* cloneGraph_DFS(Node* node) {
        if (!node)  return node;
        if (copies.find(node) == copies.end()) {    // 仅当copies中还没有node的复制节点时
            copies[node] = new Node(node->val); // 既然是未复制过的节点,那么便首先创建它并添加到copies中
            for (Node* neighbor : node->neighbors) {
                copies[node]->neighbors.push_back(cloneGraph_DFS(neighbor));    // cloneGraph_DFS(neighbor)返回的便是neighbor的复制节点
            }
        }
        return copies[node];
    }

private:
    unordered_map<Node*, Node*> copies;
};