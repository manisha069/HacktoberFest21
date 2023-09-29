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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> v;
        if(root==NULL)
            return v;
        
	// Code here
	stack<TreeNode *> s1;
	stack<TreeNode *> s2;
	s1.push(root);
	
        vector<int> a;
	while(!s1.empty()||!s2.empty())
	{  while(!s1.empty()){
	    TreeNode *temp=s1.top();
	    s1.pop();
        
	    a.push_back(temp->val);
	   
	   if(temp->left)s2.push(temp->left); 
	   if(temp->right)s2.push(temp->right);
	      
	}
     
      if(a.size()!=0) 
       {  v.push_back(a);
     a.clear();
       }  
	    
	while(!s2.empty()){
	    TreeNode *temp=s2.top();
	    s2.pop();
	    a.push_back(temp->val);
	    
	    
	        
	  if(temp->right)s1.push(temp->right);
	   if(temp->left)s1.push(temp->left);    
	        
	}
	   if(a.size()!=0) 
       {  v.push_back(a);
     a.clear();
       }  
	    
	}
	   return v;	// Code here

        
           
        
        
    }
};
