#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    // default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // value constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // full constructor
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
    void dfs(TreeNode* root, vector<int>&ans) {
        if(!root) return;
        dfs(root->left, ans);
        dfs(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int>postOrderTraversal(TreeNode* root) {
    vector<int>ans;
    dfs(root, ans);
    return ans;
    }
};

int main () {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    Solution sol;
    vector<int> result = sol.postOrderTraversal(root);
    for(int x : result) {
        cout << x << " " ;
    }
    return 0;
}