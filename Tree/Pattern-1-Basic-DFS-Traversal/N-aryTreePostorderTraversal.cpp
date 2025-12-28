#include<iostream>
#include<vector>

using namespace std;

class Node {
    public:
    int val;
    vector<Node*>children;

    Node(){}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*>_children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    public:
    void dfs(Node* root, vector<int>&ans) {
        if(!root) return;

        for(int i = 0; i < root->children.size(); i++) {
            dfs(root->children[i], ans);
        }
        ans.push_back(root->val);
    }

    vector<int>postorder(Node* root) {
    vector<int>ans;
    dfs(root, ans);
    return ans;
    }
};

int main() {
    Node* root = new Node(1);

    Node* node1 = new Node(2);
    Node* node2 = new Node(3);
    Node* node3 = new Node(4);

    root->children.push_back(node1);
    root->children.push_back(node2);
    root->children.push_back(node3);

    Node* node4 = new Node(5);
    Node* node5 = new Node(6);

    node2->children.push_back(node4);
    node2->children.push_back(node5);

    Solution sol;

    vector<int>result = sol.postorder(root);

    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}