#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // full constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // value constructor
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
    void dfs(TreeNode* root, vector<int>&ans) {
    if(!root) return;

    if(!root->left && !root->right) {
        ans.push_back(root->val);
    }

    dfs(root->left, ans); 
    dfs(root->right, ans); 

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int>ans1, ans2;    
    dfs(root1, ans1);
    dfs(root2, ans2);
    return (ans1 == ans2);
    }
};

int main() {
    // Tree 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);

    // Tree 2
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right = new TreeNode(5);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(7);
    Solution sol;
    bool result = sol.leafSimilar(root1, root2);
    cout << result;
    return 0;
}