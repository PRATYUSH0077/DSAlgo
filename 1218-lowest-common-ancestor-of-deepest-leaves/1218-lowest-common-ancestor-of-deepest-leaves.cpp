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
class Solution {
public:
    void bfs(TreeNode* root,int &cnt, int &max_depth){
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* curr=q.front().first;
            int level=q.front().second;
            q.pop();
            if(level==max_depth){
                cnt++;
            }else{
                max_depth=level;
                cnt=1;
            }
            if(curr->left!=nullptr)    {
                q.push({curr->left,level+1});
            }
            if(curr->right!=nullptr){
                q.push({curr->right,level+1});
            }
        }
        
    }
    int dfs(TreeNode* root,TreeNode* &ans,int level,int max_depth,int cnt){
        int count=0;
        if(level==max_depth){
            count++;
        }
        if(root->left){
            count+= dfs(root->left,ans,level+1,max_depth,cnt);
        }
        if(root->right){
            count+= dfs(root->right,ans,level+1,max_depth,cnt);
        }
        if(count==cnt && ans==nullptr){
            // cout<<"here1: "<<root->val<<" "<<count<<endl;
            ans=root;
        }
        // cout<<root->val<<" "<<count<<endl;
        return count;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode* ans=nullptr;
        int max_depth=-1,cnt=-1;
        bfs(root,cnt,max_depth);
        // cout<<"here: "<<max_depth<<" "<<cnt<<endl;
        int temp=dfs(root,ans,0,max_depth,cnt);
        // cout<<"here3: "<<(ans==nullptr)<<endl;
        return ans;
        
    }
};