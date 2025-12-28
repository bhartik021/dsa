#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // value constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // full constructor;
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
    
    string tree2str(TreeNode* root) {
    if(!root) return "";

    string result = to_string(root->val);
    
    if(!root->left && !root->right) {
        return result; 
    }

    result += "(" + tree2str(root->left) + ")";

    if(root->right) {
       result += "(" + tree2str(root->right) + ")"; 
    }
    return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    Solution sol;
    string result = sol.tree2str(root);
    cout << result;
    return 0;
}