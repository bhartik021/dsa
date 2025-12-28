#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    //default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // value constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // Full constructor
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
    bool dfs(TreeNode* root, int val) {
       if(!root) return true;
        
       if(root->val != val) return false;

        return dfs(root->left, root->val) &&
               dfs(root->right, root->val); 
    }

    bool isUnivalTree(TreeNode* root) {  
    if(!root) return true;
    return dfs(root, root->val);
    }
    
};

int main() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(1);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);

    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(1);

    Solution sol;
    bool result = sol.isUnivalTree(root);

    cout << boolalpha << result;
    
    return 0;
}