/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
private:
    unordered_map<int,int> mp;
public:
    FindElements(TreeNode* root) {
        root->val=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        TreeNode* node;
        int val;
        while(!q.empty()){
            node=q.front().first;
            val=q.front().second;
            mp[val]++;
            q.pop();
            if(node->left){
                node->left->val=(2*val)+1;
                q.push({node->left,node->left->val});
            }
            if(node->right){
                node->right->val=(2*val)+2;
                q.push({node->right,node->right->val});
            }
        }
    }
    
    bool find(int target) {
        return (mp.find(target)!=mp.end());
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */